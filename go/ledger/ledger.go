package ledger

import (
	"cmp"
	"errors"
	"fmt"
	"slices"
	"strconv"
	"strings"
	"time"
)

type Entry struct {
	Date        string // "Y-m-d"
	Description string
	Change      int // in cents
}

// Log:
// - use slices.SortFunc instead of custom bubble sort implementation
// - copy entries slice via slices.Clone
// - store currency and locale data in maps
// - get rid of parallelism
// - use strings.Builder to build up the output table

type localeMessages struct {
	date, description, change string
}

type localeData struct {
	dateFormat            string
	fracSep, thousandsSep byte
	messages              localeMessages
}

var localeDataMap = map[string]localeData{
	"nl-NL": {
		dateFormat:   "02-01-2006",
		fracSep:      ',',
		thousandsSep: '.',

		messages: localeMessages{
			date:        "Datum",
			description: "Omschrijving",
			change:      "Verandering",
		},
	},
	"en-US": {
		dateFormat:   "01/02/2006",
		fracSep:      '.',
		thousandsSep: ',',

		messages: localeMessages{
			date:        "Date",
			description: "Description",
			change:      "Change",
		},
	},
}

var currencySymbols = map[string]rune{
	"EUR": '€',
	"USD": '$',
}

func formatMoney(b *strings.Builder, cents int, locale localeData) {
	centsStr := strconv.Itoa(cents)

	fracIndex := max(len(centsStr)-2, 0)
	wholeStr := centsStr[:fracIndex]
	frac := centsStr[fracIndex:]

	if len(wholeStr) == 0 {
		wholeStr = "0"
	}

	rem := len(wholeStr) % 3
	if rem != 0 {
		b.WriteString(wholeStr[:rem])
		wholeStr = wholeStr[rem:]
	}

	i := 0
	quot := len(wholeStr) / 3

	for i < quot {
		if i != 0 || rem != 0 {
			b.WriteByte(locale.thousandsSep)
		}

		b.WriteString(wholeStr[:3])
		wholeStr = wholeStr[3:]
		i++
	}

	b.WriteByte(locale.fracSep)
	fmt.Fprintf(b, "%02s", frac)
}

func FormatLedger(currency string, locale string, entries []Entry) (string, error) {
	currencySymbol, ok := currencySymbols[currency]
	if !ok {
		return "", fmt.Errorf("Unsupported currency: %s", currency)
	}

	loc, ok := localeDataMap[locale]
	if !ok {
		return "", fmt.Errorf("Unsupported locale: %s", locale)
	}

	entries = slices.Clone(entries)
	slices.SortFunc(entries, func(a, b Entry) int {
		result := cmp.Compare(a.Date, b.Date)
		if result != 0 {
			return result
		}

		result = cmp.Compare(a.Description, b.Description)
		if result != 0 {
			return result
		}

		return a.Change - b.Change
	})

	builder := strings.Builder{}
	fmt.Fprintf(&builder, "%-10s | %-25s | %-13s\n", loc.messages.date, loc.messages.description, loc.messages.change)

	changeBuilder := strings.Builder{}
	for _, entry := range entries {
		date, err := time.Parse("2006-01-02", entry.Date)
		if err != nil {
			return "", errors.New("Unable to parse date")
		}

		fmt.Fprintf(&builder, "%-10s", date.Format(loc.dateFormat))

		builder.WriteString(" | ")

		if len(entry.Description) > 25 {
			builder.WriteString(entry.Description[:22])
			builder.WriteString("...")
		} else {
			fmt.Fprintf(&builder, "%-25s", entry.Description)
		}

		builder.WriteString(" | ")

		switch locale {
		case "nl-NL":
			changeBuilder.WriteRune(currencySymbol)
			changeBuilder.WriteByte(' ')

			cents := entry.Change
			if cents < 0 {
				cents = -cents
				changeBuilder.WriteByte('-')
			}

			formatMoney(&changeBuilder, cents, loc)

			changeBuilder.WriteByte(' ')
		case "en-US":
			negative := false
			cents := entry.Change
			if cents < 0 {
				cents = -cents
				negative = true
			}

			if negative {
				changeBuilder.WriteByte('(')
			}

			changeBuilder.WriteRune(currencySymbol)

			formatMoney(&changeBuilder, cents, loc)

			if negative {
				changeBuilder.WriteByte(')')
			} else {
				changeBuilder.WriteByte(' ')
			}
		}

		fmt.Fprintf(&builder, "%13s\n", changeBuilder.String())

		changeBuilder.Reset()
	}

	return builder.String(), nil
}

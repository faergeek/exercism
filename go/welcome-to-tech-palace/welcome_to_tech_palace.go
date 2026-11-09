package techpalace

import "strings"

// WelcomeMessage returns a welcome message for the customer.
func WelcomeMessage(customer string) string {
	return "Welcome to the Tech Palace, " + strings.ToUpper(customer)
}

// AddBorder adds a border to a welcome message.
func AddBorder(welcomeMsg string, numStarsPerLine int) string {
	return strings.Join([]string{
		strings.Repeat("*", numStarsPerLine),
		welcomeMsg,
		strings.Repeat("*", numStarsPerLine),
	}, "\n")
}

// CleanupMessage cleans up an old marketing message.
func CleanupMessage(oldMsg string) string {
	msg := new(strings.Builder)
	for _, r := range oldMsg {
		if r != '*' {
			msg.WriteRune(r)
		}
	}

	return strings.TrimSpace(msg.String())
}

package phonenumber

import (
	"errors"
	"fmt"
)

var (
	ErrTooManyDigits = errors.New("too many digits")
	ErrTooFewDigits  = errors.New("too few digits")
	ErrAreaCode      = errors.New("area code must start with a digit from 2 to 9")
	ErrExchangeCode  = errors.New("exchange code must start with a digit from 2 to 9")
)

func Number(phoneNumber string) (string, error) {
	var digits [10]byte
	ndigits := 0

	for _, b := range []byte(phoneNumber) {
		if b < '0' || b > '9' || ndigits == 0 && b == '1' {
			continue
		}

		if ndigits == 0 && b < '2' {
			return "", ErrAreaCode
		}

		if ndigits == 3 && b < '2' {
			return "", ErrExchangeCode
		}

		if ndigits > 9 {
			return "", ErrTooManyDigits
		}

		digits[ndigits] = b
		ndigits++
	}

	if ndigits != 10 {
		return "", ErrTooFewDigits
	}

	return string(digits[:]), nil
}

func AreaCode(phoneNumber string) (string, error) {
	cleaned, err := Number(phoneNumber)
	if err != nil {
		return "", err
	}

	return cleaned[:3], nil
}

func Format(phoneNumber string) (string, error) {
	cleaned, err := Number(phoneNumber)
	if err != nil {
		return "", err
	}

	return fmt.Sprintf(
		"(%s) %s-%s",
		cleaned[:3], cleaned[3:6], cleaned[6:],
	), nil
}

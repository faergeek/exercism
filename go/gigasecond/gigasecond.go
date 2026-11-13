// Package gigasecond provides functions to deal with time in terms of
// Gigaseconds
package gigasecond

import "time"

// AddGigasecond returns a time.Time value representing (t + 1 gigasecond).
func AddGigasecond(t time.Time) time.Time {
	return t.Add(1_000_000_000 * time.Second)
}

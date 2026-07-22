// Package weather provides all the necessary functions for working with
// weather forecasts.
package weather

var (
	// CurrentCondition is the weather condition that was forecasted the last
	// time.
	CurrentCondition string
	// CurrentLocation is the location for which weather condition was reported
	// the last time.
	CurrentLocation string
)

// Forecast updates the forecast based on given city and the weather condition.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}

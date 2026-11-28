package lasagnamaster

// PreparationTime returns the estimate for the total preparation time
// based on the number of layers. If 0 is passed as avgPrepTime, it will be
// changed to 2.
func PreparationTime(layers []string, avgPrepTime int) int {
	if avgPrepTime == 0 {
		avgPrepTime = 2
	}

	return len(layers) * avgPrepTime
}

const (
	noodleGramsPerLayer = 50
	sauceLitersPerLayer = 0.2
)

// Quantities returns the amount of noodles and sauce needed to prepare
// lasagna with the given layers.
func Quantities(layers []string) (int, float64) {
	noodleGrams := 0
	sauceLiters := 0.0

	for _, layer := range layers {
		switch layer {
		case "noodles":
			noodleGrams += noodleGramsPerLayer
		case "sauce":
			sauceLiters += sauceLitersPerLayer
		}
	}

	return noodleGrams, sauceLiters
}

// AddSecretIngredient replaces the last item in myList by the last item
// from friendsList.
func AddSecretIngredient(friendsList, myList []string) {
	myList[len(myList)-1] = friendsList[len(friendsList)-1]
}

// ScaleRecipe returns amounts of ingredients needed for the given number
// of portions based on quantitiesForTwo representing amount of ingredients
// for 2 portions.
func ScaleRecipe(quantitiesForTwo []float64, portions int) []float64 {
	quantities := make([]float64, len(quantitiesForTwo))

	for i, forTwo := range quantitiesForTwo {
		quantities[i] = forTwo * float64(portions) / 2
	}

	return quantities
}

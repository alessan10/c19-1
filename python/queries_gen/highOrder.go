package main

import "fmt"

func main() {
	var list = []string{"Orange", "Apple", "Banana", "Grape"}
	// we are passing the array and a function as arguments to mapForEach method.
	var out = mapForEach(list, func(it string) int {
		//fmt.Println(len(it))
		return len(it) //lenght of each element in the array
	})
	fmt.Println(out) // [6, 5, 6, 5]

}

// The higher-order-function takes an array and a function as arguments
func mapForEach(arr []string, fn func(it string) int) []int {
	var newArray = []int{}
	for _, it := range arr {
		// We are executing the method passed
		newArray = append(newArray, fn(it))
	}
	return newArray
}

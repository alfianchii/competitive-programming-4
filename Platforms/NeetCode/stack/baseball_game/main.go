package main

import "fmt"

func main() {
	// ops := []string{"1", "2", "+", "C", "5", "D"}
	// ops := []string{"5", "2", "C", "D", "+"}
	ops := []string{"5", "-2", "4", "C", "D", "9", "+", "+"}

	result := CalPoints(ops)

	fmt.Println(result)
}

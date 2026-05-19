package main

import "fmt"

func main() {
	// ops := []string{"1", "2", "+", "C", "5", "D"}
	ops := []string{"5", "2", "C", "D", "+"}

	result := CalPoints(ops)

	fmt.Println(result)
}

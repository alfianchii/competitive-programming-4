package main

import "fmt"

func main() {
	numMatrix := Constructor([][]int{
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5},
	})

	fmt.Println(numMatrix.SumRegion(2, 1, 4, 3)) // return 8 (i.e sum of the red rectangle)
	fmt.Println(numMatrix.SumRegion(1, 1, 2, 2)) // return 11 (i.e sum of the green rectangle)
	fmt.Println(numMatrix.SumRegion(1, 2, 2, 4)) // return 12 (i.e sum of the blue rectangle)
}

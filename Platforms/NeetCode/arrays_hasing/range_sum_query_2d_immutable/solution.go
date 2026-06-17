package main

import "fmt"

type NumMatrix struct {
	prefixes [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	rows := len(matrix)
	cols := len(matrix[0])

	prefixes := make([][]int, rows+1)
	for r := range prefixes {
		prefixes[r] = make([]int, cols+1)
	}

	// 3 0 1 4 2
	// 5 6 3 2 1
	// 1 2 0 1 5
	// 4 1 0 1 7
	// 1 0 3 0 5

	// 0  0  0  0  0  0
	// 0  3  3  4  8  10
	// 0  8  14  ?  ?  ?
	// 0  ?  ?  ?  ?  ?
	// 0  ?  ?  ?  ?  ?
	// 0  ?  ?  ?  ?  ?
	for r := 1; r <= rows; r++ { // r = 2
		for c := 1; c <= cols; c++ { // c = 2
			curr := matrix[r-1][c-1]      // 6
			top := prefixes[r-1][c]       // 3
			left := prefixes[r][c-1]      // 8
			topLeft := prefixes[r-1][c-1] // 3

			prefixes[r][c] = curr + top + left - topLeft
		}
	}

	fmt.Println(prefixes)
	return NumMatrix{prefixes: prefixes}
}

func (this *NumMatrix) SumRegion(r1 int, c1 int, r2 int, c2 int) int {
	largest := this.prefixes[r2+1][c2+1]
	top := this.prefixes[r1][c2+1]
	left := this.prefixes[r2+1][c1]
	topLeft := this.prefixes[r1][c1]

	return largest - top - left + topLeft
}

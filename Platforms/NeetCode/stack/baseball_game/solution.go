package main

import (
	"strconv"
)

type Stack struct {
	data []int
}

func (this *Stack) Push(val int) {
	this.data = append(this.data, val)
}

func (this *Stack) Pop() int {
	top := this.Top()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *Stack) Top() int {
	return this.data[len(this.data)-1]
}

func (this *Stack) IsEmpty() bool {
	return len(this.data) == 0
}

func CalPoints(ops []string) int {
	res := Stack{}

	for _, token := range ops {
		switch token {
		case "+", "D", "C":
			switch token {
			case "+":
				right := res.data[len(res.data)-1]
				left := res.data[len(res.data)-2]
				res.Push(left + right)
			case "D":
				res.Push(2 * res.Top())
			case "C":
				res.Pop()
			}
		default:
			num, _ := strconv.Atoi(token)
			res.Push(num)
		}
	}

	sum := 0
	for _, num := range res.data {
		sum += num
	}

	return sum
}

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
	stack := Stack{}
	res := Stack{}

	for _, token := range ops {
		switch token {
		case "+", "D", "C":
			switch token {
			case "+":
				left := stack.Pop()
				right := stack.Pop()
				num := left + right

				stack.Push(num)
				res.Push(num)
			case "D":
				num := 2 * res.Top()

				stack.Push(num)
				res.Push(num)
			case "C":
				stack.Pop()
				res.Pop()
			}
		default:
			num, _ := strconv.Atoi(token)
			stack.Push(num)
			res.Push(num)
		}
	}

	sum := 0
	for _, num := range res.data {
		sum += num
	}

	return sum
}

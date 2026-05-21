package main

import (
	"strings"
)

type Stack struct {
	data []string
}

func (this *Stack) Push(val string) {
	this.data = append(this.data, val)
}

func (this *Stack) Pop() string {
	top := this.Top()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *Stack) Top() string {
	return this.data[len(this.data)-1]
}

func (this *Stack) IsEmpty() bool {
	return len(this.data) == 0
}

func SimplifyPath(path string) string {
	stack := Stack{}

	parts := strings.Split(path, "/")

	for _, part := range parts {
		switch part {
		case "", ".":
			continue
		case "..":
			if !stack.IsEmpty() {
				stack.Pop()
			}
		default:
			stack.Push(part)
		}
	}

	if stack.IsEmpty() {
		return "/"
	}

	return "/" + strings.Join(stack.data, "/")
}

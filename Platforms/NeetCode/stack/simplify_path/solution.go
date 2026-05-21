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

	symbol := ""
	letter := ""
	for _, str := range path {
		switch str {
		case '/', '.':
			symbol += string(str)
			if len(letter) != 0 {
				stack.Push(letter)
				letter = ""
			}
		default:
			letter += string(str)
			for len(symbol) != 0 {
				for strings.Contains(symbol, "...") {
					stack.Push("...")

					idx := strings.Index(symbol, "...")
					symbol = symbol[idx : idx+3]
				}

				for strings.Contains(symbol, "..") && !stack.IsEmpty() {
					stack.Pop()

					idx := strings.Index(symbol, "..")
					symbol = symbol[idx : idx+2]
				}

				symbol = ""
			}
		}
	}

	if len(letter) != 0 {
		stack.Push(letter)
		letter = ""
	}

	for len(symbol) != 0 {
		for strings.Contains(symbol, "...") {
			stack.Push("...")

			idx := strings.Index(symbol, "...")
			symbol = symbol[idx : idx+3]
		}

		for strings.Contains(symbol, "..") && !stack.IsEmpty() {
			stack.Pop()

			idx := strings.Index(symbol, "..")
			symbol = symbol[idx : idx+2]
		}

		symbol = ""
	}

	fullPath := ""
	if !stack.IsEmpty() {
		for _, pathName := range stack.data {
			fullPath += "/"
			fullPath += pathName
		}
	} else {
		fullPath += "/"
	}

	return fullPath
}

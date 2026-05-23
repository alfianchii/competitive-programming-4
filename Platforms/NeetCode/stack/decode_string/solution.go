package main

import "strings"

type Pair struct {
	str    string
	repeat int
}

type Stack struct {
	data []Pair
}

func (this *Stack) Push(val Pair) {
	this.data = append(this.data, val)
}

func (this *Stack) Pop() Pair {
	top := this.Top()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *Stack) Top() Pair {
	return this.data[len(this.data)-1]
}

func (this *Stack) IsEmpty() bool {
	return len(this.data) == 0
}

func DecodeString(str string) string {
	stack := Stack{}

	currStr := ""
	currNum := 0
	for _, ch := range str {
		if ch >= '0' && ch <= '9' {
			currNum = currNum*10 + int(ch-'0')
		} else if ch == '[' {
			stack.Push(Pair{str: currStr, repeat: currNum})

			currStr = ""
			currNum = 0
		} else if ch == ']' {
			data := stack.Pop()

			repeatedString := strings.Repeat(currStr, data.repeat)
			currStr = data.str + repeatedString
		} else {
			currStr = currStr + string(ch)
		}
	}

	return currStr
}

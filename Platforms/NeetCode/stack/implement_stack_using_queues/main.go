package main

import "fmt"

func main() {
	stack := Constructor()

	stack.Push(1)
	stack.Push(2)
	fmt.Println(stack.Top())
	fmt.Println(stack.Pop())
	stack.Empty()
}

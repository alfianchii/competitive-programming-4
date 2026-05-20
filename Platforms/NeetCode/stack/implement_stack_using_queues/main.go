package main

import "fmt"

func main() {
	queue := Constructor()

	queue.Push(1)
	queue.Push(2)
	fmt.Println(queue.Top())
	fmt.Println(queue.Pop())
	queue.Empty()
}

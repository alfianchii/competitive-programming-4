package main

import "fmt"

func main() {
	queue := Constructor()

	queue.Push(1)             // queue is: [1]
	queue.Push(2)             // queue is: [1, 2] (leftmost is front of the queue)
	fmt.Println(queue.Peek()) // return 1
	fmt.Println(queue.Pop())  // return 1, queue is [2]
	queue.Empty()             // return false

}

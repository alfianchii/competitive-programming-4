package main

type MyQueue struct {
	data []int
}

func Constructor() MyQueue {
	return MyQueue{
		data: []int{},
	}
}

func (this *MyQueue) Push(x int) {
	this.data = append(this.data, x)

	n := len(this.data) - 1
	for range n {
		front := this.data[0]
		this.data = this.data[1:]
		this.data = append(this.data, front)
	}
}

func (this *MyQueue) Pop() int {
	top := this.Peek()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *MyQueue) Peek() int {
	return this.data[len(this.data)-1]
}

func (this *MyQueue) Empty() bool {
	return len(this.data) == 0
}

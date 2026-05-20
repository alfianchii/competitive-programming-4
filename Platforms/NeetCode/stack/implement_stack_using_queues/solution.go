package main

type MyStack struct {
	data []int
}

func Constructor() MyStack {
	return MyStack{
		data: []int{},
	}
}

func (this *MyStack) Push(x int) {
	this.data = append(this.data, x)

	n := len(this.data) - 1
	for range n {
		front := this.data[0]
		this.data = this.data[1:]
		this.data = append(this.data, front)
	}
}

func (this *MyStack) Pop() int {
	top := this.Top()
	this.data = this.data[1:]
	return top
}

func (this *MyStack) Top() int {
	return this.data[0]
}

func (this *MyStack) Empty() bool {
	return len(this.data) == 0
}

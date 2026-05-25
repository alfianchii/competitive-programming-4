package main

type MyQueue struct {
	inStack  []int
	outStack []int
}

func Constructor() MyQueue {
	return MyQueue{
		inStack:  []int{},
		outStack: []int{},
	}
}

func (this *MyQueue) Push(x int) {
	this.inStack = append(this.inStack, x)
}

func (this *MyQueue) Pop() int {
	this.moveInToOut()

	top := this.outStack[len(this.outStack)-1]
	this.outStack = this.outStack[:len(this.outStack)-1]
	return top
}

func (this *MyQueue) Peek() int {
	this.moveInToOut()

	return this.outStack[len(this.outStack)-1]
}

func (this *MyQueue) Empty() bool {
	return len(this.inStack) == 0 && len(this.outStack) == 0
}

func (this *MyQueue) moveInToOut() {
	if len(this.outStack) > 0 {
		return
	}

	for len(this.inStack) > 0 {
		top := this.inStack[len(this.inStack)-1]
		this.inStack = this.inStack[:len(this.inStack)-1]
		this.outStack = append(this.outStack, top)
	}
}

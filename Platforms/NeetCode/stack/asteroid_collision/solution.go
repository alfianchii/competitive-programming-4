package main

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

func AsteroidCollision(asteroids []int) []int {
	stack := Stack{}

	for _, item := range asteroids {
		if item > 0 {
			stack.Push(item)
			continue
		}

		left := stack.Top()
		right := -item

		if left > right {
			continue
		} else if left < right {
			stack.Pop()
		} else if left == right {
			stack.Pop()
			continue
		}
	}

	return stack.data
}

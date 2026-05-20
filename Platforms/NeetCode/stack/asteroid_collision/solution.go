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

	for _, asteroid := range asteroids {
		alive := true

		for alive && asteroid < 0 && !stack.IsEmpty() && stack.Top() > 0 {
			top := stack.Top()

			if top < -asteroid {
				stack.Pop()
			} else if top == -asteroid {
				stack.Pop()
				alive = false
			} else {
				alive = false
			}
		}

		if alive {
			stack.Push(asteroid)
		}
	}

	return stack.data
}

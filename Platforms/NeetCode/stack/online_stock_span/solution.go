package main

type StockSpanner struct {
	data []int
}

func Constructor() StockSpanner {
	return StockSpanner{
		data: []int{},
	}
}

func (this *StockSpanner) Push(val int) {
	this.data = append(this.data, val)
}

func (this *StockSpanner) Pop() int {
	top := this.Top()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *StockSpanner) Top() int {
	return this.data[len(this.data)-1]
}

func (this *StockSpanner) IsEmpty() bool {
	return len(this.data) == 0
}

func (this *StockSpanner) Next(price int) int {
	this.Push(price)

	days := 1
	n := len(this.data)
	for i := 1; i <= n-1; i++ {
		currPrice := this.data[len(this.data)-i]
		prevPrice := this.data[len(this.data)-(i+1)]

		if currPrice <= price && prevPrice <= price {
			days++
		}
	}

	return days
}

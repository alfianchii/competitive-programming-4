package main

type Pair struct {
	price int
	days  int
}

type StockSpanner struct {
	data []Pair
}

func Constructor() StockSpanner {
	return StockSpanner{
		data: []Pair{},
	}
}

func (this *StockSpanner) Push(val Pair) {
	this.data = append(this.data, val)
}

func (this *StockSpanner) Pop() Pair {
	top := this.Top()
	this.data = this.data[:len(this.data)-1]
	return top
}

func (this *StockSpanner) Top() Pair {
	return this.data[len(this.data)-1]
}

func (this *StockSpanner) IsEmpty() bool {
	return len(this.data) == 0
}

func (this *StockSpanner) Next(price int) int {
	days := 1

	for !this.IsEmpty() && this.Top().price <= price {
		top := this.Pop()
		days += top.days
	}

	this.Push(Pair{price: price, days: days})

	return days
}

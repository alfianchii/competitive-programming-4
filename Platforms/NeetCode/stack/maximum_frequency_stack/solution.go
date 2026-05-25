package main

type FreqStack struct {
	freqs   map[int]int
	groups  map[int][]int
	maxFreq int
}

func Constructor() FreqStack {
	return FreqStack{
		freqs:   make(map[int]int),
		groups:  make(map[int][]int),
		maxFreq: 0,
	}
}

func (this *FreqStack) Push(val int) {
	this.freqs[val]++
	currentFreq := this.freqs[val]
	this.groups[currentFreq] = append(this.groups[currentFreq], val)
	if currentFreq > this.maxFreq {
		this.maxFreq = currentFreq
	}
}

func (this *FreqStack) Pop() int {
	mostFreqs := this.groups[this.maxFreq]
	val := mostFreqs[len(mostFreqs)-1]
	this.groups[this.maxFreq] = mostFreqs[:len(mostFreqs)-1]
	this.freqs[val]--

	if this.freqs[val] == 0 {
		delete(this.freqs, val)
	}

	if len(this.groups[this.maxFreq]) == 0 {
		delete(this.groups, this.maxFreq)
		this.maxFreq--
	}

	return val
}

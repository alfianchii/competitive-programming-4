package main

type FreqStack struct {
	stack []int
	freq  map[int]int
}

func Constructor() FreqStack {
	return FreqStack{
		stack: []int{},
		freq:  make(map[int]int),
	}
}

func (this *FreqStack) Push(val int) {
	this.stack = append(this.stack, val)
	this.freq[val]++
}

func (this *FreqStack) Pop() int {
	mostFreq := 0
	mostFreqVal := 0
	mostFreqIdx := 0
	for idx := len(this.stack) - 1; idx >= 0; idx-- {
		val := this.stack[idx]
		freq := this.freq[val]
		if freq > mostFreq {
			mostFreq = freq
			mostFreqIdx = idx
			mostFreqVal = val
		}
	}

	if len(this.stack) > 1 {
		this.stack = append(this.stack[:mostFreqIdx], this.stack[mostFreqIdx+1:]...)
	} else {
		this.stack = this.stack[:len(this.stack)-1]
	}
	this.freq[mostFreqVal]--

	return mostFreqVal
}

func (this *FreqStack) Top() int {
	return this.stack[len(this.stack)-1]
}

package main

type FreqStack struct {
	stack []int
	freq  []int
}

func Constructor() FreqStack {
	return FreqStack{}
}

func (this *FreqStack) Push(val int) {
	this.stack = append(this.stack, val)
	this.freq[val]++
}

func (this *FreqStack) Pop() int {
	this.stack = this.stack[:len(this.stack)-1]

	mostFreqIdx := 0
	mostFreq := 0
	for idx, val := range this.stack {
		freq := this.freq[idx]
		if freq > mostFreqIdx {
			mostFreqIdx = freq
			mostFreq = val
		}
	}

	this.stack = append(this.stack[:mostFreqIdx], this.stack[mostFreqIdx+1:]...)

	return mostFreq
}

func (this *FreqStack) Top() int {
	return this.stack[len(this.stack)-1]
}

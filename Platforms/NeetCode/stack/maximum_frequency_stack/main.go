package main

import "fmt"

func main() {
	freqStack := Constructor()

	freqStack.Push(5)            // The stack is [5]
	freqStack.Push(7)            // The stack is [5,7]
	freqStack.Push(5)            // The stack is [5,7,5]
	freqStack.Push(7)            // The stack is [5,7,5,7]
	freqStack.Push(4)            // The stack is [5,7,5,7,4]
	freqStack.Push(5)            // The stack is [5,7,5,7,4,5]
	fmt.Println(freqStack.Pop()) // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
	fmt.Println(freqStack.Pop()) // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
}

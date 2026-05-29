package main

func TopKFrequent(nums []int, k int) []int {
	count := make(map[int]int)
	freqs := make([][]int, len(nums)+1)

	for _, num := range nums {
		count[num]++
	}

	for num, freq := range count {
		freqs[freq] = append(freqs[freq], num)
	}

	res := []int{}
	for i := len(freqs) - 1; i >= 0 && len(res) < k; i-- {
		res = append(res, freqs[i]...)
	}

	return res
}

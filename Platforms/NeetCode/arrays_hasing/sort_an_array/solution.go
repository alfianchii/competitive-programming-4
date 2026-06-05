package main

func SortArray(nums []int) []int {
	const minVal = -50000
	const maxVal = 50000

	offset := -minVal
	countSize := maxVal - minVal + 1

	freqs := make([]int, countSize)
	for _, num := range nums {
		freqs[num+offset]++
	}

	idx := 0
	for i := range countSize { // 0 -> 100001
		num := i - offset // -50000

		for freqs[i] > 0 {
			nums[idx] = num
			idx++
			freqs[i]--
		}
	}

	return nums
}

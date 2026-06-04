package main

func LongestConsecutive(nums []int) int {
	freqs := make(map[int]bool)

	for _, num := range nums {
		freqs[num] = true
	}

	longest := 0
	for num := range freqs {
		if !freqs[num-1] {
			current := num
			length := 1

			for freqs[current+1] {
				current++
				length++
			}

			if length > longest {
				longest = length
			}
		}
	}

	return longest
}

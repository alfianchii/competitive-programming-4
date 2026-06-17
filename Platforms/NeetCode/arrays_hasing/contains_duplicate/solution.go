package main

func HasDuplicate(nums []int) bool {
	freqs := make(map[int]bool)

	for _, num := range nums {
		if freqs[num] {
			return true
		}

		freqs[num] = true
	}

	return false
}

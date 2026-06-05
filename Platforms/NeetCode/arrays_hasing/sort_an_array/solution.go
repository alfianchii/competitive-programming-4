package main

func SortArray(nums []int) []int {
	n := len(nums)

	for range n {
		for i := 0; i < n-1; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
			}
		}
	}

	return nums
}

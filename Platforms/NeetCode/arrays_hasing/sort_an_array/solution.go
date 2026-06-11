package main

func merge(left, right []int) []int {
	result := make([]int, 0, len(left)+len(right))

	i, j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	for i < len(left) {
		result = append(result, left[i])
		i++
	}
	for j < len(right) {
		result = append(result, right[j])
		j++
	}

	return result
}

func mergeSort(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	}

	// 5 2 4 1
	// 5 2 // 4 1
	// 5 // 2 // 4 // 1
	mid := len(nums) / 2           // 1
	left := mergeSort(nums[:mid])  // 5
	right := mergeSort(nums[mid:]) // 2

	return merge(left, right)
}

func SortArray(nums []int) []int {
	return mergeSort(nums)
}

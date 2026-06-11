# [Sort Colors](https://neetcode.io/problems/sort-colors/)

## Problem

You are given an array `nums` consisting of `n` elements where each element is an integer representing a color:

- `0` represents red
- `1` represents white
- `2` represents blue

Your task is to sort the array in-place such that elements of the same color are grouped together and arranged in the order: red (0), white (1), and then blue (2).

You must not use any built-in sorting functions to solve this problem.

### Example 1

```go
Input: nums = [1,0,1,2]
Output: [0,1,1,2]
```

### Example 2

```go
Input: nums = [2,1,0]
Output: [0,1,2]
```

### Constraints

- `1 <= nums.length <= 300`
- `0 <= nums[i] <= 2`

---

## Brute Force Intuition

Just use a normal sorting algorithm such as Bubble Sort, I guess AHAHAHAHA.

## OK (Counting Sort)

I can count how many times each color appears. After counting, overwrite the original array. Well well since the value range is extremely small, counting is more efficient than using a general-purpose sorting algorithm.

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

## Edge Cases

- ?

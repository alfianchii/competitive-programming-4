# [Sort an Array](https://neetcode.io/problems/sort-an-array/)

## Problem

You are given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

### Example 1

```go
Input: nums = [10,9,1,1,1,2,3,1]
Output: [1,1,1,1,2,3,9,10]
```

### Example 2

```go
Input: nums = [5,10,2,1,3]
Output: [1,2,3,5,10]
```

### Constraints

- `1 <= nums.length <= 50,000`
- `-50,000 <= nums[i] <= 50,000`

---

## Brute Force Intuition

The brute force (maybe?) way is to use Bubble Sort by repeatedly comparing two adjacent elements and swapping them if they are in the wrong order. After one full pass, the largest value moves to the end of the array. Repeating this process eventually makes the whole array sorted. But to slow for n^2.

## OK (Counting Sort)

Use Counting Sort instead because the value range is limited by the constraint. Instead of comparing elements, count how many times each number appears. Since array indexes cannot be negative, use an `offset` to shift every number into a valid index. After counting all numbers, rebuild `nums` from the smallest possible value to the largest possible value. If a number appears multiple times, write it multiple times into `nums`.

## OK (Merge Sort)

Well, since the problem requires `O(n log (n))` time complexity, Merge Sort is a OK choice. The idea is to divide the array into smaller halves until each subarray contains only one element. A single element is already sorted, so we can then merge two sorted halves back together while maintaining sorted order.

## Complexity Analysis

### Counting Sort

- Time Complexity: O(n + k)
- Space Complexity: O(k)

### Merge Sort

- Time Complexity: O(n log n)
- Space Complexity: O(n)

## Edge Cases

- Array with only one element, for example `[1]`
- Array with duplicate values, for example `[1, 1, 1, 2, 2]`
- Array with negative numbers, for example `[-3, -1, -2]`
- Array containing both minimum and maximum values, for example `[50000, -50000, 0]`

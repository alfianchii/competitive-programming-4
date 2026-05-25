# [Asteroid Collision](https://neetcode.io/problems/asteroid-collision/)

## Problem

You are given an array asteroids of integers representing `asteroids` in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

### Example 1

```go
Input: asteroids = [2,4,-4,-1]
Output: [2]
```

### Example 2

```go
Input: asteroids = [5,5]
Output: [5,5]
```

### Example 3

```go
Input: asteroids = [7,-3,9]
Output: [7,9]
```

### Constraints

- `2 <= asteroids.length <= 10,000`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

---

## Brute Force Intuition

Repeatedly scan the array and look for two adjacent asteroids that will collide. After a collision, remove the destroyed asteroid or asteroids, then scan again because the new neighboring asteroids may also collide. This works, but it can be inefficient because after every collision, I may need to scan the array again.

## OK (Stack)

Use a stack to store asteroids that are still alive. Read the asteroids from left to right. For each new asteroid, compare it only with the top of the stack when a collision is possible. When a collision happens, compare their sizes using absolute values. Since the stack top is positive and the current asteroid is negative, the current asteroid's size can be checked with `-asteroid`.

## Complexity Analysis

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

## Edge Cases

- No collisions happen
- Two asteroids with the same size collide and both explode

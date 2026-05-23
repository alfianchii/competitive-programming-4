# [Decode String](https://neetcode.io/problems/decode-string/)

## Problem

You are given an encoded string `s`, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the encoded_string inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. There will not be input like `3a`, `2[4]`, `a[a]` or `a[2]`.

The test cases are generated so that the length of the output will never exceed `100,000`.

### Example 1

```go
Input: s = "2[a3[b]]c"
Output: "abbbabbbc"
```

### Example 2

```go
Input: s = "axb3[z]4[c]"
Output: "axbzzzcccc"
```

### Example 3

```go
Input: s = "ab2[c]3[d]1[x]"
Output: "abccdddx"
```

### Constraints

- `1 <= s.length <= 30`
- `s` is made up of lowercase English letters, digits, and square brackets `'[]'`
- All the integers in `s` are in the range `[1, 300]`
- `s` is guaranteed to be a valid input

---

## Brute Force Intuition

N/A

## OK (Stack)

Use a stack to store the previous state before entering a new bracket. While traversing the string from left to right, keep two variables, `currStr` for the string currently being built, and `currNum` for the repeat number currently being parsed. When a digit appears, build `currNum`. This is needed because the repeat number can have more than one digit, such as `12[a]` or `300[a]`.

When `'['` appears, push the current state into the stack as `(currStr, currNum)`, then reset `currStr` and `currNum`. This means we are now starting to build the string inside the bracket. When `']'` appears, the current bracket content is complete. Pop the previous state from the stack, repeat `currStr` using the popped repeat count, and append it to the popped previous string. When a normal letter appears, append it to `currStr`.

## Complexity Analysis

- Time Complexity: `O(n + m)`
- Space Complexity: `O(n + m)`

## Edge Cases

- Nested encoded strings, for example `"2[a3[b]]"`
- Multi-digit repeat numbers, for example `"12[a]"`

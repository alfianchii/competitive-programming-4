# [Baseball Game](https://neetcode.io/problems/baseball-game/)

## Problem

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

Given a list of strings `operations`, where `operations[i]` is the `ith` operation you must apply to the record and is one of the following:

- An integer `x`: Record a new score of `x`.
- '+': Record a new score that is the sum of the previous two scores.
- 'D': Record a new score that is the double of the previous score.
- 'C': Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.

Note: The test cases are generated such that the answer and all intermediate calculations fit in a `32`-bit integer and that all operations are valid.

### Example 1

```go
Input: ops = ["1","2","+","C","5","D"]
Output: 18
```

Explanation:

- `"1"` - Add 1 to the record, record = [1].
- `"2"` - Add 2 to the record, record = [1, 2].
- `"+"` - Add `1 + 2 = 3` to the record, record = [1, 2, 3].
- `"C"` - Invalidate and remove the previous score, record = [1, 2].
- `"5"` - Add 5 to the record, record = [1, 2, 5].
- `"D"` - Add `2 * 5 = 10` to the record, record = [1, 2, 5, 10].
- The total sum is `1 + 2 + 5 + 10 = 18`.

### Example 2

```go
Input: ops = ["5","D","+","C"]
Output: 15
```

Explanation:

- `"5"` - Add 5 to the record, record = [5].
- `"D"` - Add `2 * 5 = 10` to the record, record = [5, 10].
- `"+"` - Add `5 + 10 = 15` to the record, record = [5, 10, 15].
- `"C"` - Invalidate and remove the previous score, record = [5, 10].
- The total sum is `5 + 10 = 15`.

### Constraints

- `1 <= operations.length <= 1000`
- `operations[i]` is `"C"`, `"D"`, `+`, or a string representing an integer in the range `[(-30,000), (30,000)]`
- For operation `"+"`, there will always be at least two previous scores on the record
- For operations `"C"` and `"D"`, there will always be at least one previous score on the record

---

## Brute Force Intuition

N/A

## OK (Stack)

Use a stack to store the valid scores in the record. Read the operations from left to right. If the token is a number, convert it to integer and push it into the stack. If the token is `"D"`, push double of the previous score. If the token is `"+"`, push the sum of the previous two scores. If the token is `"C"`, remove the previous score from the stack.

The stack represents the current record, so when all operations are done, sum all values left in the stack.

## Complexity Analysis

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

## Edge Cases

- Operation `"+"` must use the previous two scores without removing them

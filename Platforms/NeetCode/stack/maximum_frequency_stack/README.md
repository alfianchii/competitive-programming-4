# [Maximum Frequency Stack](https://neetcode.io/problems/maximum-frequency-stack/)

## Problem

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:

- `FreqStack()` constructs an empty frequency stack.
- `void push(int val)` pushes an integer val onto the top of the stack.
- `int pop()` removes and returns the most frequent element in the stack.
- - If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

### Example 1

```go
Input: ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output: [null, null, null, null, null, null, null, 5, 7, 5, 4]
```

Explanation:

```go
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop(); // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop(); // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

### Constraints

- `0 <= val <= 1,000,000,000`
- At most `20,000` calls will be made to `push` and `pop`
- It is guaranteed that there will be at least one element in the stack before calling `pop`

---

## Brute Force Intuition

Actually here I can use a normal stack to store all pushed values and use a frequency table to count how many times each value appears. For `push`, append the value into the stack and increase its frequency. For `pop`, scan the stack from right to left. Since the right side is the top of the stack, scanning from right to left helps handle the tie rule. When I find a value with a higher frequency than the current best frequency, I store that value and its index. After the scan is done, remove that value from the stack and decrease its frequency. It works BUT it is inefficient because every `pop` may scan the whole stack. Removing an element from the middle of a slice is also expensive because the elements after it need to shift.

## OK (Hash Map + Frequency Stack)

Use two hash maps (`freqs` and `groups`) and keep the max freq. When pushing a value, increase its frequency. Then push that value into `groups[currentFreq]`. If the new frequency is greater than `maxFreq`, update `maxFreq`. The important idea is that `groups[freq]` does not mean "all values that currently have this frequency". Instead, it stores the order of values when they reached that
frequency.

If `pop` is called, take the last value from `groups[maxFreq]`. This gives the most frequent value. If there is a tie, the last value in that group is the one closest to the top of the stack. After popping, decrease the frequency of that value. If `groups[maxFreq]` becomes empty, decrease `maxFreq`.

## Complexity Analysis

- Time Complexity: `O(1)`
- Space Complexity: `O(n)`

## Edge Cases

- Multiple values have the same frequency
- The most frequent group becomes empty after `pop`
- Only one element exists before calling `pop`

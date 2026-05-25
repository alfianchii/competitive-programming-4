# [Implement Queue using Stacks](https://neetcode.io/problems/implement-queue-using-stacks/)

## Problem

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

- `void push(int x)` Pushes element `x` to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is `empty`, false otherwise.

Notes:

- You must use only standard operations of a stack, which means only `push` to `top`, `peek/pop` from `top`, `size`, and is `empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

### Example 1

```go
Input: ["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output: [null, null, null, 1, 1, false]
```

Explanation:

```go
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

### Constraints

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`
- All the calls to `pop` and `peek` are valid

Follow-up: Can you implement the queue such that each operation is [amortized](https://en.wikipedia.org/wiki/Amortized_analysis) O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

---

## Brute Force Intuition

Use a normal slice like a queue: push new values to the back, then `peek` and `pop` from the front. This works as a queue, but it does not follow the problem constraint because a stack only allows access from the top. In a slice, the stack top is usually the last element. So directly using `data[0]` or removing `data[0]` is a queue operation, not a stack operation.

## OK (Two Stacks)

Use two stacks, are `inStack` stores new elements when `push` is called and `outStack` stores elements in reversed order so the queue front is on top. When pushing a new value, just push it into `inStack`. When `peek` or `pop` is called, the front of the queue must be returned. If `outStack` already has elements, its top is the current queue front. If `outStack` is empty, move all elements from `inStack` to `outStack`. This reverses the order.

## Complexity Analysis

- Time Complexity:
- - `push`: O(1)
- - `pop`: amortized `O(1)`, worst-case `O(n)`
- - `peek`: amortized `O(1)`, worst-case `O(n)`
- - `empty`: O(1)
- Space Complexity: `O(n)`

## Edge Cases

N/A

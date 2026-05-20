# [Implement Stack Using Queues](https://neetcode.io/problems/implement-stack-using-queues/)

## Problem

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

- `void push(int x)` Pushes element `x` to the top of the stack.
- `int pop()` Removes the element on the top of the stack and returns it.
- `int top()` Returns the element on the top of the stack.
- `boolean empty()` Returns true if the stack is empty, false otherwise.

Notes:

- You must use only standard operations of a queue, which means that only `push` to `back`, `peek/pop from front`, `size` and `is empty` operations are valid.
- Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

### Example 1

```go
Input: ["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output: [null, null, null, 2, 2, false]
```

Explanation:

```go
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

### Constraints

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `top`, and `empty`
- All the calls to `pop` and `top` are valid

Follow-up: Can you implement the stack using only one queue?

---

## Brute Force Intuition

Use a normal slice as a stack directly. Push new elements to the end of the slice, and for pop or top, access the last element. This works as a stack, but it does not follow the problem constraint because a queue only allows access from the front. Accessing or removing the last element is a stack/list operation, not a queue operation.

- Time Complexity: `O(1)` for `push`, `pop`, `top`, and `empty`
- Space Complexity: `O(n)`

## OK (One Queue)

Use one queue and make the newest pushed element move to the front of the queue. This way, the front of the queue always represents the top of the stack. When pushing a new value, push the new value to the back of the queue, rotate all previous elements by popping from the front and pushing them back to the back, and after rotation, the new value becomes the front of the queue.

## Complexity Analysis

- Time Complexity:
- - Push: `O(n)`
- - Pop: `O(1)`
- - Top: `O(1)`
- - Empty: `O(1)`
- Space Complexity: `O(n)`

## Edge Cases

N/A

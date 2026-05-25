# [Online Stock Span](https://neetcode.io/problems/online-stock-span/)

## Problem

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The **span** of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

- For example, if the prices of the stock in the last four days is `[7,2,1,2]` and the price of the stock today is `2`, then the span of today is `4` because starting from today, the price of the stock was less than or equal `2` for `4` consecutive days.
- Also, if the prices of the stock in the last four days is `[7,34,1,2]` and the price of the stock today is `8`, then the span of today is `3` because starting from today, the price of the stock was less than or equal `8` for `3` consecutive days.

Implement the `StockSpanner` class:

- `StockSpanner()` Initializes the object of the class.
- `int next(int price)` Returns the span of the stock's price given that today's price is price.

### Example 1

```go
Input: ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output: [null, 1, 1, 1, 2, 1, 4, 6]
```

Explanation:

```go
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80); // return 1
stockSpanner.next(60); // return 1
stockSpanner.next(70); // return 2
stockSpanner.next(60); // return 1
stockSpanner.next(75); // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85); // return 6
```

### Constraints

- `1 <= price <= 100,000`

---

## Brute Force Intuition

Store all previous prices in an array. Every time `next(price)` is called, start from today's price and scan backward while the previous prices are less than or equal to today's price. Count how many consecutive prices satisfy that condition. Stop when a greater price is found. This works, but it repeats work. For example, if prices keep increasing, every new call may scan all previous prices again.

## OK (Monotonic Stack)

Use a monotonic decreasing stack to store pairs of `(price, days)`. The `price` is the stock price, and `days` is the span represented by that price. When a new price comes in, start with `days = 1` because today itself always counts. Then, while the stack is not empty and the top price is less than or equal to the current price, pop the top pair and add its `days` to the current `days`.

## Complexity Analysis

- Time Complexity: `O(1)`
- Space Complexity: `O(n)`

## Edge Cases

- Duplicate prices
- Current price is greater than all previous prices

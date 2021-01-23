---
title: 509. Fibonacci Number
tags: leetcode
---

https://leetcode.com/problems/fibonacci-number/

## Idea

## Code

```cpp=
class Solution {
 public:
  int fib(int n) {
    if (m.count(n) < 1) m[n] = fib(n - 1) + fib(n - 2);
    return m[n];
  }

 private:
  std::unordered_map<int, int> m{{0, 0}, {1, 1}};
};
```
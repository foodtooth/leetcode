---
title: 225. Implement Stack using Queues
tags: leetcode
---

https://leetcode.com/problems/implement-stack-using-queues/

## Idea

## Code

```cpp=
class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { q.push(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    while (q.size() > 1) {
      tmp.push(q.front());
      q.pop();
    }
    int result{};
    if (q.size() == 1) {
      result = q.front();
      q.pop();
    }
    std::swap(q, tmp);
    return result;
  }

  /** Get the top element. */
  int top() { return q.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q.empty(); }

 private:
  std::queue<int> q{};
  std::queue<int> tmp{};
};
```
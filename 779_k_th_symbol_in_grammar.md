---
title: 779. K-th Symbol in Grammar
tags: leetcode
---

https://leetcode.com/problems/k-th-symbol-in-grammar/

## Idea

## Code
```cpp
class Solution {
 public:
  int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    return K % 2 == kthGrammar(N - 1, std::ceil(K / 2.)) ? 1 : 0;
  }
};
```
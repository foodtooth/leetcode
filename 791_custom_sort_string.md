---
title: 791. Custom Sort String
tags: leetcode
---

https://leetcode.com/problems/custom-sort-string/

## Idea

## Code

```cpp=
class Solution {
 public:
  string customSortString(string S, string T) {
    std::sort(T.begin(), T.end(),
              [&S](char a, char b) { return S.find(a) < S.find(b); });
    return T;
  }
};
```
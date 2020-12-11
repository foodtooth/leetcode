---
title: 406. Queue Reconstruction by Height
tags: leetcode
---

https://leetcode.com/problems/queue-reconstruction-by-height/

## Idea
通常数组对，还涉及排序的，以第一个元素正向排序，同时第二个元素反向，可以简化解题过程。本题排序后，可以通过例子的观察和实际操作，看出最终`insert people`操作的规律。

## Code

```cpp=
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    std::sort(people.begin(), people.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a.front() > b.front() ||
                       (a.front() == b.front() && a.back() < b.back());
              });
    std::vector<std::vector<int>> tmp{};
    for (auto const &v : people) {
      tmp.insert(tmp.begin() + v.back(), v);
    }
    return tmp;
  }
};
```
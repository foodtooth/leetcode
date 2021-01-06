---
title: 836. Rectangle Overlap
tags: leetcode
---

https://leetcode.com/problems/rectangle-overlap/

## Idea
overlap的情况很多，使用取反的方式，把不会overlap的四种情况考虑到即可

## Code

```cpp=
class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    if (IsLineOrDot(rec1) || IsLineOrDot(rec2)) return false;
    return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] ||
             rec1[3] <= rec2[1]);
  }

 private:
  bool IsLineOrDot(std::vector<int>& rec) {
    if (rec[0] - rec[2] == 0 || rec[1] - rec[3] == 0)
      return true;
    else
      return false;
  }
};
```
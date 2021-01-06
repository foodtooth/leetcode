---
title: 223. Rectangle Area
tags: leetcode
---

https://leetcode.com/problems/rectangle-area/

## Idea

## Code

```cpp=
class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    std::vector<int> rec1{A, B, C, D};
    std::vector<int> rec2{E, F, G, H};
    auto sum = (long long)(C - A) * (D - B) + (G - E) * (H - F);
    if (isRectangleOverlap(rec1, rec2)) {
      sum -=
          (std::min(C, G) - std::max(A, E)) * (std::min(D, H) - std::max(B, F));
    }
    return (int)sum;
  }

 private:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    if (IsLineOrDot(rec1) || IsLineOrDot(rec2)) return false;
    return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] ||
             rec1[3] <= rec2[1]);
  }

  bool IsLineOrDot(std::vector<int>& rec) {
    if (rec[0] - rec[2] == 0 || rec[1] - rec[3] == 0)
      return true;
    else
      return false;
  }
};
```
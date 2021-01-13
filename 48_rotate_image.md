---
title: 48. Rotate Image
tags: leetcode
---

https://leetcode.com/problems/rotate-image/

## Idea

### Straight forward

旋转，很直白的方式就是想象成轮子在转。在矩阵中，就是每一层ring中，把每个item swap三次

### Common tips for rotation

可以通过两次翻转达成旋转的效果，顺逆时针都可以。详见下面代码及注释

## Code

```cpp=
class Solution {
 public:
  /*
   * clockwise rotation:
   * first reverse up to down, then swap the symmetry
   * 1 2 3    7 8 9    7 4 1
   * 4 5 6 => 4 5 6 => 8 5 2
   * 7 8 9    1 2 3    9 6 3
   */
  void rotate(vector<vector<int>>& matrix) {
    std::reverse(matrix.begin(), matrix.end());
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    for (int i{}; i < row_size; ++i) {
      for (int j{i + 1}; j < col_size; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }

  /*
   * anticlockwise rotation:
   * first reverse left to right, then swap the symmetry
   * 1 2 3     3 2 1     3 6 9
   * 4 5 6  => 6 5 4  => 2 5 8
   * 7 8 9     9 8 7     1 4 7
   */
  void anti_rotate(vector<vector<int>>& matrix) {
    for (auto const& v : matrix) std::reverse(v.begin(), v.end());
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    for (int i{}; i < row_size; ++i) {
      for (int j{i + 1}; j < col_size; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
```
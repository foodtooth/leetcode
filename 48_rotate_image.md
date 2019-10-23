https://leetcode.com/problems/rotate-image/

## Idea
Clockwise 90 degrees rotation.

按圈轮换。每圈需要轮换(边长 - 1 - 圈数)次。两个变量决定循环的方式和要交换的变量。

[Smart one](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image) from leetcode, which I do not really understand the theory behind.

## Code
```cpp
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int edge_len = matrix[0].size();
    for (int circle = 0; circle < edge_len / 2; ++circle) {
      for (int step = circle; step < edge_len - 1 - circle; ++step) {
        std::swap(matrix[circle][step], matrix[edge_len - 1 - step][circle]);
        std::swap(matrix[edge_len - 1 - step][circle],
                  matrix[edge_len - 1 - circle][edge_len - 1 - step]);
        std::swap(matrix[edge_len - 1 - circle][edge_len - 1 - step],
                  matrix[step][edge_len - 1 - circle]);
      }
    }
  }
};
```
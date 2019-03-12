https://leetcode.com/problems/container-with-most-water/

## Code

```cpp
class Solution {
 public:
  // 最大面积由两个因素决定。两线之间的距离，还有两线之间较短的那条的高度；
  // 我们控制其中一个变量的变化方向，再通过有节制地变化另一个，从而比较出最大面积值。
  int maxArea(vector<int>& height) {
    int result = 0;
    int max = 0;
    int height_len = height.size();
    bool growing = false;

    int i = 0, j = height_len - 1;
    while (i < j) {
      growing = height[i] < height[j];
      max = (j - i) * (growing ? height[i] : height[j]);
      if (result < max) {
        result = max;
      }
      if (growing) {
        ++i;
      } else {
        --j;
      }
    }
    return result;
  }

  // Brute Force
  int maxArea2(vector<int>& height) {
    int result = 0;
    int max = 0;
    int height_len = height.size();
    for (int i = 0; i < height_len; ++i) {
      for (int j = i + 1; j < height_len; ++j) {
        max = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
        if (result < max) {
          result = max;
        }
      }
    }
    return result;
  }
};
```
https://leetcode.com/problems/3sum-closest/

## Idea
乱序意味着无法预知后面，意味着必须全体遍历，便意味着效率低。

可以结合[15_3sum](./15_3sum.md)食用。

## Code

```cpp
#include <algorithm>
#include <climits>

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    int nums_size = nums.size();
    int first, last, temp, result;
    int min = INT_MAX;
    for (int i = 0; i < nums_size - 2; ++i) {
      first = i + 1;
      last = nums_size - 1;

      while (first < last) {
        temp = nums[i] + nums[first] + nums[last];
        if (temp > target) {
          if (temp - target < min) {
            result = temp;
            min = temp - target;
          }
          while (last - 1 > first && nums[last - 1] == nums[last])
            --last;
          --last;
        } else if (temp < target) {
          if (target - temp < min) {
            result = temp;
            min = target - temp;
          }
          while (first + 1 < last && nums[first + 1] == nums[first])
            ++first;
          ++first;
        } else
          return target;
      }
    }
    return result;
  }
};
```
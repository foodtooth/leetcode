https://leetcode.com/problems/median-of-two-sorted-arrays/

## Code

```cpp
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> nums { };
    int len1 = nums1.size();
    int len2 = nums2.size();
    int i { };
    int j { };

    while (i < len1 && j < len2) {
      if (nums1[i] < nums2[j]) {
        nums.push_back(nums1[i]);
        ++i;
      } else {
        nums.push_back(nums2[j]);
        ++j;
      }
    }
    if (i < len1)
      nums.insert(nums.end(), nums1.begin() + i, nums1.end());
    if (j < len2)
      nums.insert(nums.end(), nums2.begin() + j, nums2.end());

    int len = nums.size();
    if (len % 2 == 0)
      return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;
    else
      return nums[(len + 1) / 2 - 1] * 1.0;
  }
};
```
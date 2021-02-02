---
title: 34. Find First and Last Position of Element in Sorted Array
tags: leetcode
---

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

## Idea

## Code

```cpp=
class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    std::vector<int> result{};
    int nums_size = nums.size();
    int left{0}, right{nums_size - 1};
    // 算左侧起始
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] == target) {
        right = mid - 1;
      }
    }
    result.push_back((left >= nums_size || nums[left] != target) ? -1 : left);
    right = nums_size - 1;
    // 算右侧结束；两次方法很相似，注意index的移动、边界判断和最后的异常判断即可
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] == target) {
        left = mid + 1;
      }
    }
    result.push_back((right < 0 || nums[right] != target) ? -1 : right);
    return result;
  }
};
```
---
title: 704. Binary Search
tags: leetcode
---

https://leetcode.com/problems/binary-search/

## Idea

```cpp=
int binarySearch(int[] nums, int target) {
  int left = 0, right = ...;
  while (...) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      ...
    } else if (nums[mid] < target) {
      left = ...;
    } else if (nums[mid] > target) {
      right = ...;
    }
  }
  return ...;
}
```

## Code

```cpp=
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int left{0}, right{static_cast<int>(nums.size() - 1)};
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
    }
    return -1;
  }
};
```
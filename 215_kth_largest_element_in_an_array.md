---
title: 215. Kth Largest Element in an Array
tags: leetcode
---

https://leetcode.com/problems/kth-largest-element-in-an-array/

## Idea

## Code
```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    return *std::next(nums.begin(), k - 1);
  }
};
```
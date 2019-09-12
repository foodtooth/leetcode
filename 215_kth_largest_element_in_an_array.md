---
title: 215. Kth Largest Element in an Array
tags: leetcode
---

https://leetcode.com/problems/kth-largest-element-in-an-array/

## Idea
Except for the normal way of sorting-and-pick, we only need partial sorted array for this problem. STL provides [partial_sort](https://en.cppreference.com/w/cpp/algorithm/partial_sort) and [nth_element](https://en.cppreference.com/w/cpp/algorithm/nth_element) for it. And we can use heap structure to get the nth item partially. STL provides [priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) and [multiset](https://en.cppreference.com/w/cpp/container/multiset) for heap-like usage.

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
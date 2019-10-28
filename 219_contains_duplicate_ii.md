---
title: 219. Contains Duplicate II
tags: leetcode
---

https://leetcode.com/problems/contains-duplicate-ii/

## Idea
Hash table.

## Code
```cpp
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    bool result{};
    std::unordered_map<int, int> checker{};
    int nums_size = nums.size();

    for (int i{}; i < nums_size; ++i) {
      if (checker[nums[i]] == 0) {
        checker[nums[i]] = i + 1;
      } else {
        if (i + 1 - checker[nums[i]] <= k) {
          result = true;
          break;
        } else {
          checker[nums[i]] = i + 1;
        }
      }
    }

    return result;
  }
};
```
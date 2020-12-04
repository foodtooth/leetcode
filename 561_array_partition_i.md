---
title: 561. Array Partition I
tags: leetcode
---

https://leetcode.com/problems/array-partition-i/

## Idea

## Code

```cpp=
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto nums_size = nums.size();
    int result{};
    for (int i{}; i < nums_size; i += 2) {
      result += nums[i];
    }
    return result;
  }
};
```
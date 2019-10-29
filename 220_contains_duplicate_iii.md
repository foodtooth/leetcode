---
title: 220. Contains Duplicate III
tags: leetcode
---

https://leetcode.com/problems/contains-duplicate-iii/

## Idea

## Code
```cpp
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    bool result{};
    if (t < 0) return result;
    int nums_size = nums.size();
    std::map<int, int> checker{};

    for (int i{}; i < nums_size; ++i) {
      if (checker.empty()) {
        // Handle first-time condition
        checker[nums[i]] = i;
      } else {
        // Find proper value of current range in checker

        // Extra diff and sum variable to handle int-overflow
        int diff{};
        if (std::numeric_limits<int>::min() + t > nums[i]) {
          diff = std::numeric_limits<int>::min();
        } else {
          diff = nums[i] - t;
        }
        auto p = checker.lower_bound(diff);
        int sum{};
        if (std::numeric_limits<int>::max() - t < nums[i]) {
          sum = std::numeric_limits<int>::max();
        } else {
          sum = nums[i] + t;
        }
        auto q = checker.upper_bound(sum);

        while (p != q) {
          if (i - p->second <= k) {
            result = true;
            return result;
          } else {
            ++p;
          }
        }
        checker[nums[i]] = i;
      }
    }

    return result;
  }
};
```
---
title: 217. Contains Duplicate
tags: leetcode
---

https://leetcode.com/problems/contains-duplicate/

## Idea
Hash table.

## Code
```cpp
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    bool result{false};
    std::unordered_map<int, bool> checker{};
    for (const auto& i : nums) {
      if (checker[i]) {
        result = true;
        break;
      } else {
        checker[i] = true;
      }
    }
    return result;
  }
};
```
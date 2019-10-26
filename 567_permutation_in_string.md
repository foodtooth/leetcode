---
title: 567. Permutation in String
tags: leetcode
---

https://leetcode.com/problems/permutation-in-string/

## Idea

## Code
```cpp
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int s1_length = s1.length();
    int s2_length = s2.length();
    if (s1_length > s2_length) return false;
    std::array<int, 26> s1_counter{};
    std::array<int, 26> s2_counter{};
    for (auto& c : s1) {
      ++s1_counter[c - 'a'];
    }

    // We can simply use operator= to compare two vector, instead of this
    // confusing one using `false_counter`.
    int i{};
    std::array<bool, 26> comparison{};
    comparison.fill(true);
    int false_counter{};
    for (; i < s1_length; ++i) {
      auto cur = ++s2_counter[s2[i] - 'a'];
      if (cur > s1_counter[s2[i] - 'a']) {
        if (comparison[s2[i] - 'a']) {
          comparison[s2[i] - 'a'] = false;
          ++false_counter;
        }
      }
    }
    if (false_counter == 0) {
      return true;
    }

    for (i = 1; i < s2_length - s1_length + 1; ++i) {
      auto cur = ++s2_counter[s2[i + s1_length - 1] - 'a'];
      if (cur > s1_counter[s2[i + s1_length - 1] - 'a']) {
        if (comparison[s2[i + s1_length - 1] - 'a']) {
          comparison[s2[i + s1_length - 1] - 'a'] = false;
          ++false_counter;
        }
      }
      cur = --s2_counter[s2[i - 1] - 'a'];
      if (cur == s1_counter[s2[i - 1] - 'a']) {
        comparison[s2[i - 1] - 'a'] = true;
        --false_counter;
      }
      if (false_counter == 0) {
        return true;
      }
    }
    return false;
  }
};
```
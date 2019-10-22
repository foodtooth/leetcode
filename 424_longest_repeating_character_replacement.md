---
title: 424. Longest Repeating Character Replacement
tags: leetcode
---

https://leetcode.com/problems/longest-repeating-character-replacement/

## Idea
Sliding Window.

## Code
```cpp
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int s_length = s.length();
    int window_start{};
    int max_length{};
    std::array<int, 26> char_counter{};
    int max_in_windows{};
    for (int window_end{window_start}; window_end < s_length; ++window_end) {
      auto t = ++char_counter[s[window_end] - 'A'];
      max_in_windows = std::max(max_in_windows, t);

      // edge case
      if (window_end - window_start + 1 - max_in_windows > k) {
        --char_counter[s[window_start] - 'A'];
        ++window_start;
      }

      max_length = std::max(max_length, window_end - window_start + 1);
    }

    return max_length;
  }
};
```
---
title: 76. Minimum Window Substring
tags: leetcode
---

https://leetcode.com/problems/minimum-window-substring/

## Idea

## Code
```cpp
class Solution {
 public:
  string minWindow(string s, string t) {
    std::string result{};
    std::string_view s_v{s};
    int smallest_len{-1};
    int s_len = s.length(), t_len = t.length();

    std::unordered_map<int, int> s_counter{}, t_counter{};

    for (const auto& i : t) {
      ++t_counter[i];
    }
    int fault_counter = t_counter.size();

    bool holds_tail{false};
    for (int window_start{}, window_end{}; window_end < s_len;) {
      if (!holds_tail) {
        ++s_counter[s[window_end]];
        if (t_counter.find(s[window_end]) != t_counter.end() &&
            s_counter[s[window_end]] == t_counter[s[window_end]])
          --fault_counter;
      } else {
        holds_tail = false;
      }
      if (fault_counter == 0) {
        if (window_end - window_start + 1 < smallest_len ||
            smallest_len == -1) {
          smallest_len = window_end - window_start + 1;
          result = s_v.substr(window_start, smallest_len);
        }

        if (t_counter.find(s[window_start]) != t_counter.end() &&
            s_counter[s[window_start]] == t_counter[s[window_start]])
          ++fault_counter;
        --s_counter[s[window_start]];
        ++window_start;
        holds_tail = true;
      } else {
        ++window_end;
      }
    }

    return result;
  }
};
```
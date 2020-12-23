---
title: 28. Implement strStr()
tags: leetcode
---

https://leetcode.com/problems/implement-strstr/

## Idea

### KMP

LPS含义，一个pattern的表，用于在mismatch之后最大限度减少重复比较的次数。LPS stands for "Longest proper Prefix which is also Suffix".

## Code

1. Basic two pointers

    ```cpp=
    class Solution {
     public:
      int strStr(string haystack, string needle) {
        int hay_len = haystack.length();
        int needle_len = needle.length();
        if (needle_len == 0) return 0;
        for (int i{}; i < hay_len - needle_len + 1; ++i) {
          int j{};
          for (; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j]) break;
          }
          if (j == needle_len) return i;
        }
        return -1;
      }
    };
    ```
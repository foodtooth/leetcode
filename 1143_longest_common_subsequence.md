---
title: 1143. Longest Common Subsequence
tags: leetcode
---

https://leetcode.com/problems/longest-common-subsequence/

## Idea

## Code
1. dp

    ```cpp=
    class Solution {
     public:
      int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        for (int i{1}; i <= n; ++i) {
          for (int j{1}; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
              dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
              dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
          }
        }
        return dp[n][m];
      }
    };
    ```
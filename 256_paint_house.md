---
title: 256. Paint House
tags: leetcode
---

[![hackmd-github-sync-badge](https://hackmd.io/8rc55QRnRAm5wnic3N96sw/badge)](https://hackmd.io/8rc55QRnRAm5wnic3N96sw)

https://leetcode.com/problems/paint-house

## Idea

## Code
1. DP

    ```cpp=
    class Solution {
     public:
      /**
       * @param costs: n x 3 cost matrix
       * @return: An integer, the minimum cost to paint all houses
       */
      int minCost(vector<vector<int>> &costs) {
        if (costs.empty()) return 0;
        auto dp =
            std::vector<std::vector<int>>(costs.size(), std::vector<int>(3, 0));
        auto size = costs.size();
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        int i{1};
        for (; i < size; ++i) {
          dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
          dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
          dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
      }
    };
    ```
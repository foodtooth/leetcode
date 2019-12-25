---
title: 1283. Find the Smallest Divisor Given a Threshold
tags: leetcode
---

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

## Idea

## Code
1. Straight forward

    ```cpp=
    class Solution {
     public:
      int smallestDivisor(vector<int> &nums, int threshold) {
        std::sort(nums.begin(), nums.end());
        int left{1}, right{nums[nums.size() - 1]};
        int i = left;
        auto lmd = [&i](long sum, int v) {
          auto t = std::ceil(v / float(i));
          if (std::numeric_limits<int>::max() - sum < t) {
            return (long)std::numeric_limits<int>::max() + 1;
          } else {
            sum += t;
            return sum;
          }
        };
        if (std::accumulate(nums.begin(), nums.end(), 0L, lmd) <= threshold)
          return left;

        i = (left + right) / 2;
        while (i != 0) {
          auto ok = std::accumulate(nums.begin(), nums.end(), 0L, lmd) <= threshold;
          if (ok) {
            right = i;
          } else {
            left = i;
          }
          if (left + 1 == right) {
            return right;
          } else {
            i = (left + right) / 2;
          }
        }
        return -1;
      }
    };
    ```
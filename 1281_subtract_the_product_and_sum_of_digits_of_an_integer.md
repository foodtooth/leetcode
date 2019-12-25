---
title: 1281. Subtract the Product and Sum of Digits of an Integer
tags: leetcode
---

https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

## Idea

## Code
1. Straight forward

    ```cpp=
    class Solution {
     public:
      int subtractProductAndSum(int n) {
        int product{1};
        int sum{0};
        while (n > 0) {
          auto i = n % 10;
          product *= i;
          sum += i;
          n /= 10;
        }
        return product - sum;
      }
    };
    ```
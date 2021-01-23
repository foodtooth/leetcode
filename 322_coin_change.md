---
title: 322. Coin Change
tags: leetcode
---

https://leetcode.com/problems/coin-change/

## Idea

DP问题的一般形式就是求最值。难点在于**写出状态转移方程**：
> 明确base case -> 明确[状态] -> 明确[选择] -> 定义dp数组/函数的含义

可以得到如此框架：
```cpp=
// 初始化base case
dp[0][0][...] = base
// 进行状态转移
for 状态1 in 状态1的所有值:
  for 状态2 in 状态2的所有值:
    for ...:
      dp[状态1][状态2][...] = 求最值(选择1，选择2，...)
```

## Code

```cpp=
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // 定义dp为要达到第i amount时，最小数量的coins是dp[i]
    // 所以dp[amount]即为结果；而初始化dp[x]为amount+1是因为这是全为1面值coin的最多数量情况
    // 同时amount+1的初始违例状态可以帮助判断不满足要求的场景
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    // 当我们遍历到最后的amount，也即达成了目的
    for (int cur_amount{1}; cur_amount <= amount; ++cur_amount) {
      // 每个amount我们都需要穷举所有面值coin的情况
      for (int coin : coins) {
        if (cur_amount - coin < 0) continue;
        dp[cur_amount] = std::min(dp[cur_amount], dp[cur_amount - coin] + 1);
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
```
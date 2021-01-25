---
title: 46. Permutations
tags: leetcode
---

https://leetcode.com/problems/permutations/

## Idea

## Code

```cpp=
class Solution {
 public:
  // 回溯法的思路，其实也就是遍历树的过程，在不同操作节点处理数据插入与取出，达成全遍历的结果
  vector<vector<int>> permute(vector<int> &nums) {
    std::vector<std::vector<int>> result{};
    std::vector<int> cur{};
    auto nums_size = nums.size();
    std::vector<int> used(nums_size);
    std::function<void()> dfs = [&]() {
      if (cur.size() == nums_size) {
        result.push_back(cur);
        return;
      }
      for (std::size_t i{}; i < nums_size; ++i) {
        if (used[i] == 1) continue;
        cur.push_back(nums[i]);
        used[i] = 1;
        dfs();
        cur.pop_back();
        used[i] = 0;
      }
    };
    dfs();
    return result;
  }
};
```
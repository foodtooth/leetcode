---
title: 78. Subsets
tags: leetcode
---

https://leetcode.com/problems/subsets/

## Idea

普通思路，会分别考虑每个新的值加入到subset中时的情况；使用回溯法，会遵循一定的编程思路

```cpp=
result {};
backtrack(选择列表，路径):
  if (满足结束条件):
    result.add(路径结果);
    return
  for 选择 in 选择列表:
    做选择
    backtrack(新选择列表，新路径)
    撤销选择
```

## Code

```cpp=
class Solution {
 public:
  // iterator
  vector<vector<int>> subsets(vector<int> &nums) {
    std::vector<std::vector<int>> result{};
    result.emplace_back();
    process(result, nums);
    return result;
  }

  // recursive (backtrack)
  vector<vector<int>> subsets2(vector<int> &nums) {
    std::vector<std::vector<int>> result{};
    std::vector<int> sub{};
    backtrack(nums, 0, sub, result);
    return result;
  }

 private:
  void process(std::vector<std::vector<int>> &result, std::vector<int> &nums) {
    for (auto i : nums) {
      int n = result.size();
      for (int index{}; index < n; ++index) {
        result.push_back(result[index]);
        result.back().push_back(i);
      }
    }
  }

  void backtrack(std::vector<int> &nums, int target_level,
                 std::vector<int> &sub, std::vector<std::vector<int>> &subs) {
    subs.push_back(sub);
    for (int j{target_level}; j < nums.size(); ++j) {
      sub.push_back(nums[j]);
      backtrack(nums, j + 1, sub, subs);
      sub.pop_back();
    }
  }
};
```
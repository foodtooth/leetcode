---
title: 894. All Possible Full Binary Trees
tags: leetcode
---

https://leetcode.com/problems/all-possible-full-binary-trees/

## Idea

## Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<TreeNode *> allPossibleFBT(int N) {
    // 处理基本的特殊情况
    if (N % 2 == 0) return {};
    if (N == 1) return {new TreeNode(0)};
    if (!cache_[N].empty()) return cache_[N];
    std::vector<TreeNode *> &result = cache_[N];
    // 明显的子问题结构，N的所有枚举可以由左儿子1, 3, ..., 2k + 1及右儿子N - 1,
    // N - 3...的所有相同子问题枚举的组合而成。
    // 我们还可以通过cache，把2k + 1对应的树存起来，减少迭代次数
    for (int i = 1; i < N - 1; i += 2) {
      for (const auto &l : allPossibleFBT(i)) {
        for (const auto &r : allPossibleFBT(N - 1 - i)) {
          auto root = new TreeNode(0);
          root->left = l;
          root->right = r;
          result.emplace_back(root);
        }
      }
    }
    return result;
  }

 private:
  static const int kMaxNodes_ = 20 + 1;
  std::array<std::vector<TreeNode *>, kMaxNodes_> cache_{};
};
```
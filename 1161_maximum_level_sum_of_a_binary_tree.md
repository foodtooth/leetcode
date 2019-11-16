---
title: 1161. Maximum Level Sum of a Binary Tree
tags: leetcode
---

https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
  int maxLevelSum(TreeNode *root) {
    std::queue<std::pair<TreeNode *, int>> q{};
    q.emplace(root, 1);
    std::pair<int, int> r{std::numeric_limits<int>::min(), 0};
    std::pair<int, int> p{0, 1};  // sum, level
    while (!q.empty()) {
      auto [node, counter] = q.front();
      q.pop();
      if (counter != p.second) {
        if (p.first > r.first) {
          r.first = p.first;
          r.second = p.second;
        }
        p.second = counter;
        p.first = node->val;
      } else {
        p.first += node->val;
      }
      if (node->left) q.emplace(node->left, counter + 1);
      if (node->right) q.emplace(node->right, counter + 1);
    }
    if (p.first > r.first) r.second = p.second;
    return r.second;
  }
};
```
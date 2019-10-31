---
title: 102. Binary Tree Level Order Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;
    BreadthFirstTraversal(root, result);
    return result;
  }
  void BreadthFirstTraversal(TreeNode *node,
                             std::vector<std::vector<int>> &res) {
    std::queue<std::pair<TreeNode *, int>> q{};
    if (node == NULL) return;
    q.emplace(node, 1);
    while (!q.empty()) {
      auto [n, counter] = q.front();
      q.pop();
      if (res.size() < counter)
        res.emplace_back(std::initializer_list<int>{n->val});
      else
        res[counter - 1].push_back(n->val);
      if (n->left) q.emplace(n->left, counter + 1);
      if (n->right) q.emplace(n->right, counter + 1);
    }
  }
};
```
---
title: 257. Binary Tree Paths
tags: leetcode
---

https://leetcode.com/problems/binary-tree-paths/

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
  vector<string> binaryTreePaths(TreeNode *root) {
    if (root == NULL) return {};
    std::vector<std::string> result{};
    if (root->left == NULL && root->right == NULL) {
      return {std::to_string(root->val)};
    }
    if (root->left != NULL) {
      for (const auto &s : binaryTreePaths(root->left)) {
        result.emplace_back(std::to_string(root->val) + "->" + s);
      }
    }
    if (root->right != NULL) {
      for (const auto &s : binaryTreePaths(root->right)) {
        result.emplace_back(std::to_string(root->val) + "->" + s);
      }
    }
    return result;
  }
};
```
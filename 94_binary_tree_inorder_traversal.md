---
title: 94. Binary Tree Inorder Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-inorder-traversal/

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
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    worker(root, result);
    return result;
  }

  void worker(TreeNode *node, std::vector<int> &result) {
    if (node == NULL) return;
    worker(node->left, result);
    result.push_back(node->val);
    worker(node->right, result);
  }
};
```
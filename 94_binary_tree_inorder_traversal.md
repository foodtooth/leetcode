---
title: 94. Binary Tree Inorder Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-inorder-traversal/

## Idea

## Code
1. Recursive
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

2. Iterative
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
    creeper(root, result);
    return result;
  }
  void creeper(TreeNode *node, std::vector<int> &res) {
    std::stack<TreeNode *> s{};
    while (!s.empty() || node != NULL) {
      while (node != NULL) {
        s.push(node);
        node = node->left;
      }
      node = s.top();
      s.pop();
      res.push_back(node->val);
      node = node->right;
    }
  }
};
```
---
title: 112. Path Sum
tags: leetcode
---

https://leetcode.com/problems/path-sum/

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
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return sum == root->val;
    bool result{false};
    if (root->left != NULL && hasPathSum(root->left, sum - root->val))
      result = true;
    if (root->right != NULL && hasPathSum(root->right, sum - root->val))
      result = true;
    return result;
  }
};
```
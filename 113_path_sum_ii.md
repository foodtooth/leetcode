---
title: 113. Path Sum II
tags: leetcode
---

https://leetcode.com/problems/path-sum-ii/

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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (root == NULL) return {};
    if (root->left == NULL && root->right == NULL) {
      if (root->val == sum)
        return {{root->val}};
      else
        return {};
    }
    std::vector<std::vector<int>> result{};
    if (root->left != NULL) {
      for (auto &v : pathSum(root->left, sum - root->val)) {
        v.insert(v.begin(), root->val);
        result.push_back(v);
      }
    }
    if (root->right != NULL) {
      for (auto &v : pathSum(root->right, sum - root->val)) {
        v.insert(v.begin(), root->val);
        result.push_back(v);
      }
    }
    return result;
  }
};
```
---
title: 572. Subtree of Another Tree
tags: leetcode
---

https://leetcode.com/problems/subtree-of-another-tree/

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
  bool isSubtree(TreeNode *s, TreeNode *t) {
    std::queue<TreeNode *> q{};
    if (s != NULL) q.push(s);
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (isSame(n, t)) return true;
      if (n != NULL) {
        q.push(n->left);
        q.push(n->right);
      }
    }
    return false;
  }
  bool isSame(TreeNode *x, TreeNode *y) {
    if (x == NULL && y == NULL)
      return true;
    else if (x == NULL || y == NULL)
      return false;
    if (x->val == y->val)
      return isSame(x->left, y->left) && isSame(x->right, y->right);
    else
      return false;
  }
};
```
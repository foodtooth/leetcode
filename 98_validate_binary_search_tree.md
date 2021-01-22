---
title: 98. Validate Binary Search Tree
tags: leetcode
---

https://leetcode.com/problems/validate-binary-search-tree/

## Idea

## Code

1. Iterative in-order traversal

    ```cpp=
    class Solution {
     public:
      bool isValidBST(TreeNode *root) { return creeper(root); }

      bool creeper(TreeNode *node) {
        std::stack<TreeNode *> s{};
        long min = std::numeric_limits<long>::min();
        while (!s.empty() || node != NULL) {
          while (node != NULL) {
            s.push(node);
            node = node->left;
          }
          node = s.top();
          s.pop();
          if (node->val <= min)
            return false;
          else
            min = node->val;
          node = node->right;
        }
        return true;
      }
    };
    ```
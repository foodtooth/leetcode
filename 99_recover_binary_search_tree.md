---
title: 99. Recover Binary Search Tree
tags: leetcode
---

https://leetcode.com/problems/recover-binary-search-tree/

## Idea

## Code

```cpp=
class Solution {
 public:
  void recoverTree(TreeNode *root) {
    InOrder(root);
    int temp{};
    temp = first_->val;
    first_->val = second_->val;
    second_->val = temp;
  }

 private:
  void InOrder(TreeNode *node) {
    if (node == nullptr) return;
    InOrder(node->left);
    // BST的inorder本该是由小到大的数列
    // 我们找出不符合排序的，进而找到该调整的两个数
    if (prev_ != nullptr && prev_->val > node->val) {
      // 实际举例可以看出
      // the first time we found an incorrect pair, the prev_ node must be the
      // first incorrect node.
      if (first_ == nullptr) first_ = prev_;
      // the curr node is always the second incorrect node.
      second_ = node;
    }
    // 无论前面比较的情况如何，当前的node都将成为下次的prev
    prev_ = node;
    InOrder(node->right);
  }
  TreeNode *prev_{nullptr};
  TreeNode *first_{nullptr};
  TreeNode *second_{nullptr};
};
```
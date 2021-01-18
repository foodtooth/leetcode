---
title: 226. Invert Binary Tree
tags: leetcode
---

https://leetcode.com/problems/invert-binary-tree/

## Idea

## Code

```cpp=
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    Recursive(root);
    return root;
  }

 private:
  void Recursive(TreeNode *root) {
    if (root == nullptr) return;
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
  }
  // BFS亦或是PreOrder DFS等等都可以
  void Iterative(TreeNode *root) {
    if (root == nullptr) return;
    std::queue<TreeNode *> queue{};
    queue.push(root);
    while (!queue.empty()) {
      auto n = queue.front();
      queue.pop();
      std::swap(n->left, n->right);
      if (n->left != nullptr) queue.push(n->left);
      if (n->right != nullptr) queue.push(n->right);
    }
  }
};
```
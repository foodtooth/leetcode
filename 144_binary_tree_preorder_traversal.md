---
title: 144. Binary Tree Preorder Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-preorder-traversal/

## Idea

## Code

```cpp=
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    Recursive(root, result);
    return result;
  }

 private:
  void Recursive(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) return;
    result.push_back(node->val);
    Recursive(node->left, result);
    Recursive(node->right, result);
  }
  void Iterative(TreeNode *node, std::vector<int> &result) {
    // 特殊场景，传入root为空的时候
    if (node == nullptr) return;
    // 用于存储遍历时节点，通过入栈顺序保证preorder
    std::stack<TreeNode *> stack{};
    // root入栈，开始iteration
    stack.push(node);
    // 当栈不为空
    while (!stack.empty()) {
      // 拿出栈数据，preorder需要先访问根数据，这里的访问行为只是单纯的放入result
      auto n = stack.top();
      result.push_back(n->val);
      stack.pop();
      // 先压右，再压左，以保证出栈时先左后右，成为preorder
      if (n->right != nullptr) stack.push(n->right);
      if (n->left != nullptr) stack.push(n->left);
    }
  }
};
```
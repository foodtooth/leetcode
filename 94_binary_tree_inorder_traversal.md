---
title: 94. Binary Tree Inorder Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-inorder-traversal/

## Idea

## Code

```cpp=
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    Recursive(root, result);
    return result;
  }

 private:
  void Recursive(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) return;
    Recursive(node->left, result);
    result.push_back(node->val);
    Recursive(node->right, result);
  }
  // 通过使用Recursive的实际例子，也可以大概看出Iterative的过程
  void Iterative(TreeNode *node, std::vector<int> &result) {
    std::stack<TreeNode *> stack{};
    while (!stack.empty() || node != nullptr) {
      // 此处从左压栈，直到有nullptr，是Recursive中第一个Recursive函数的部分
      while (node != nullptr) {
        stack.push(node);
        node = node->left;
      }
      // 此处是确认再无左子树，所以处理根节点。是Recursive中中间的push result
      auto n = stack.top();
      result.push_back(n->val);
      stack.pop();
      // 此处是Recursive中第二个Recursive函数的部分；使右子树为当前node，然后走回整个循环的判断流程里
      if (n->right != nullptr) node = n->right;
    }
  }
};
```
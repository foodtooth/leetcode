---
title: 102. Binary Tree Level Order Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Idea

## Code

```cpp=
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    // 存储最终的层级结果
    std::vector<std::vector<int>> result{};
    if (root == nullptr) return result;
    // 使用先入先出的queue达到层级遍历的效果
    std::queue<TreeNode *> queue{};
    queue.push(root);
    while (!queue.empty()) {
      int cur_level_size = queue.size();
      // 为这一层新建一个临时存储点
      std::vector<int> cur_level{};
      // 将在这个循环中把本层内容全部处理
      while (cur_level_size-- > 0) {
        auto n = queue.front();
        queue.pop();
        cur_level.push_back(n->val);
        if (n->left != nullptr) queue.push(n->left);
        if (n->right != nullptr) queue.push(n->right);
      }
      result.push_back(cur_level);
    }
    return result;
  }
};
```
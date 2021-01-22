---
title: 124. Binary Tree Maximum Path Sum
tags: leetcode
---

https://leetcode.com/problems/binary-tree-maximum-path-sum/

## Idea

## Code

```cpp=
class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    SingleSizeMax(root);
    return sum_;
  }

 private:
  int SingleSizeMax(TreeNode *node) {
    if (node == nullptr) return 0;
    // 我们此时计算以node为根的左右两子树的max，是为了保证当前以node为根的最大path；
    // 如果两侧有小于0的，自然不需要那部分path
    int left = std::max(0, SingleSizeMax(node->left));
    int right = std::max(0, SingleSizeMax(node->right));
    // 所以此处用当前sum比较新的以node为根的最大path
    sum_ = std::max(sum_, node->val + left + right);
    // 但是如果是返回值，意味着我们对上一个node只是一侧；
    // 也就是我们身为其path的一侧，肯定无法自己把自己下面的两侧都涵盖在内，只能取大的一侧
    return std::max(left, right) + node->val;
  }
  int sum_{std::numeric_limits<int>::min()};
};
```
---
title: 437. Path Sum III
tags: leetcode
---

https://leetcode.com/problems/path-sum-iii/

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
  int pathSum(TreeNode *root, int sum) {
    if (root == NULL) return 0;
    sum_ = sum;
    return traverse(root, {{sum_, 1}});
  }

  int traverse(TreeNode *node, std::unordered_map<int, int> cands) {
    int cur{0};
    if (cands.find(node->val) != cands.end()) {
      cur += cands[node->val];
    }
    if (node->left != NULL || node->right != NULL) {
      std::unordered_map<int, int> tmp_map{};
      for (auto it = cands.begin(); it != cands.end(); it) {
        auto nh = cands.extract(it++);
        nh.key() -= node->val;
        tmp_map.insert(tmp_map.end(), std::move(nh));
      }
      tmp_map.swap(cands);
      cands[sum_] += 1;

      if (node->left != NULL) {
        cur += traverse(node->left, cands);
      }
      if (node->right != NULL) {
        cur += traverse(node->right, cands);
      }
    }

    return cur;
  }

 private:
  int sum_{};
};
```
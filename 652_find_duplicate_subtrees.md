---
title: 652. Find Duplicate Subtrees
tags: leetcode
---

https://leetcode.com/problems/find-duplicate-subtrees/

## Idea
要找重复，一定要有所有子树的集合，如果再已有集合中发现了当前值（用遍历出的子树的字符序列表示子树），就是重复；又因为拿到此重复值所在节点，考虑用`map(key=subtree_str, value=treenode)`

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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::unordered_map<std::string, int> checker{};
    std::vector<TreeNode *> result{};
    creeper(root, checker, result);
    return result;
  }
  std::string creeper(TreeNode *node,
                      std::unordered_map<std::string, int> &checker,
                      std::vector<TreeNode *> &res) {
    if (node == NULL) return "NULL";
    std::string key{"("};
    key += creeper(node->left, checker, res);
    key += std::to_string(node->val);
    key += creeper(node->right, checker, res);
    key += ")";
    if (checker.find(key) != checker.end() && checker[key] == 1) {
      res.push_back(node);
    }
    ++checker[key];
    return key;
  }
};
```
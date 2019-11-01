---
title: 919. Complete Binary Tree Inserter
tags: leetcode
---

https://leetcode.com/problems/complete-binary-tree-inserter/

## Idea
### Complete binary tree related calculation
Let complete binary tree be $T$ with height $h$, and node number $N$, and it is constructed using a $N$-lengh array.

1. The maximum number of nodes in level $k(k \geq 1)$ is $2^{k-1}$
2. The maximum number of nodes in the tree is $2^k - 1$
3. The number of leaf nodes in the tree is
\begin{cases}
\frac N2, & \text{if $N$ is even} \\
\frac {N + 1}2, & \text{if $N$ is odd}
\end{cases}
4. If a parent node is at index $i$ in the array, then the left child of that node is at index $2i + 1$ and right child is at index $2i + 2$ in the array.
5. The index of current opening node(waiting for inserting new node) is $\lceil \frac N2 \rceil - 1$ or $\lfloor \frac {N - 1}2 \rfloor$.

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
class CBTInserter {
 public:
  CBTInserter(TreeNode *root) {
    nodes.push_back(root);
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i]->left != NULL) nodes.push_back(nodes[i]->left);
      if (nodes[i]->right != NULL) nodes.push_back(nodes[i]->right);
    }
  }

  int insert(int v) {
    TreeNode *node = new TreeNode(v);
    auto count = nodes.size();
    auto index = static_cast<int>(std::ceil(count / 2.)) - 1;
    //    auto index = (count - 1) / 2;  // same as the `std::ceil` one
    if (count % 2 == 0) {
      nodes[index]->right = node;
    } else {
      nodes[index]->left = node;
    }
    nodes.push_back(node);
    return nodes[index]->val;
  }

  TreeNode *get_root() { return nodes[0]; }

  std::vector<TreeNode *> nodes{};
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
```
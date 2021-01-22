---
title: 105. Construct Binary Tree from Preorder and Inorder Traversal
tags: leetcode
---

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

## Idea

## Code

```cpp=
class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // 首先，我们需要通过两个遍历方式的结果判断出树的样子，然后递归构造树即可
    // 原则如下：
    // 1. preorder[0]为树的root
    // 2. preorder[x]为子树的root
    // 3. inorder中找到preorder里root的index后，其0 - index-1的值为左子树；
    //    index+1到最右为右子树；没有即为空（nullptr）
    // 方法：我们通过递归，把每一个root和子树都创建出来
    int root_index{};
    return Build(preorder, inorder, root_index, 0, preorder.size() - 1);
  }

 private:
  TreeNode *Build(std::vector<int> &preorder, std::vector<int> &inorder,
                  int &root_index, int left, int right) {
    if (left > right) return nullptr;
    // 定义pivot作为root在inorder中的index，每次计算
    int pivot = left;
    while (inorder[pivot] != preorder[root_index]) ++pivot;
    // 创建新的root节点
    TreeNode *new_node = new TreeNode(inorder[pivot]);
    // 开始以下一个preorder里的root_index的递归
    ++root_index;
    // root_index在左侧的Build递归中正好加到右侧需要的范围里
    new_node->left = Build(preorder, inorder, root_index, left, pivot - 1);
    new_node->right = Build(preorder, inorder, root_index, pivot + 1, right);
    return new_node;
  }
};
```
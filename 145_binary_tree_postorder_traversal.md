---
title: 145. Binary Tree Postorder Traversal
tags: leetcode
---

https://leetcode.com/problems/binary-tree-postorder-traversal/

## Idea

### 后记

三序遍历已经完成，最简单易懂的Recursive，需要细致考虑访问顺序的Iteration都已经完成。可以看出，Recursive中两个连续Recursive的调用也只是stack的形式而已，所以催生前序和后序那两个类似的写法；而如果非Recursive操作掺杂其中，比如中序，反而比较复杂。

这里再说一个Morris Traversal，它就是把二叉树偏向一个方向，从而达到不让非Recursive的访问操作插在中间的效果。简单说比如，遇到有左子树的根节点，就把根节点作为左子树的最右节点的右孩子（这样会保证大小关系）

## Code

```cpp=
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    Recursive(root, result);
    return result;
  }

 private:
  void Recursive(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) return;
    Recursive(node->left, result);
    Recursive(node->right, result);
    result.push_back(node->val);
  }
  // 仍然可以通过Recursive例子看出端倪
  void Iterative(TreeNode *node, std::vector<int> &result) {
    std::stack<TreeNode *> stack{};
    TreeNode *pre{nullptr};
    while (!stack.empty() || node != nullptr) {
      // 此处从左压栈，直到有nullptr，是Recursive中第一个Recursive函数的部分
      while (node != nullptr) {
        stack.push(node);
        node = node->left;
      }
      // 需要先使用一下根，但是不能弹出，是否弹出要根据下面描述的右节点访问情况而定
      auto n = stack.top();

      // 中序时在此已经确认没有左子树，会直接访问此时的根；
      // 但后序时，还要把右子树的访问放在根前面，所以还要优先右的判断
      // 至于如何判断此时的右是否已经访问，可以通过在stack中放入标志位标识
      // 或者通过记录上一个访问过的节点来进行比较

      // 右节点为空或者右节点已经被访问过（与上次保存的访问节点相同），直接访问根节点
      if (n->right == nullptr || n->right == pre) {
        stack.pop();
        // 访问根节点
        result.push_back(n->val);
        // 记录访问以便判断
        pre = n;
      } else {
        node = n->right;
      }
    }
  }
  // 前序中已经通过入栈顺序保证了根->左->右的访问顺序，后序访问顺序左->右->根，可以看出是
  // 前序顺序的调换和一点点变更
  void Iterative2(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) return;
    std::stack<TreeNode *> stack{};
    stack.push(node);
    while (!stack.empty()) {
      auto n = stack.top();
      result.push_back(n->val);
      stack.pop();
      // 通过与前序类似的方式我们会得到根->右->左的访问结果，那后序只是再reverse一次而已
      if (n->left != nullptr) stack.push(n->left);
      if (n->right != nullptr) stack.push(n->right);
    }
    // 或者前面result不用vector而是一个stack，在此挨个放入最终vector（即通过一个stack反转）
    // 亦或是在上面插入时直接从前插入（使用deque）
    std::reverse(result.begin(), result.end());
  }
};
```
---
title: 111. Minimum Depth of Binary Tree
tags: leetcode
---

https://leetcode.com/problems/minimum-depth-of-binary-tree/

## Idea

### BFS

由于一层一层走的特性，通常用于计算从起点到终点的最小距离。什么是终点由场景决定，如果是图，需要判断是否已经走过。

```cpp=
int BFS(Node start, Node target) {
  Queue<Node> q;
  Set<Node> visited;
  
  q.push(start);
  visited.add(start);
  // 记录往外扩散的层数
  int step {1};
  
  while (q is not empty) {
    int size_of_cur_level = q.size();
    for (i in size_of_cur_level) {
      Node cur = q.pop();
      // 此时根据具体场景判断是否到达终点
      if (cur is target)
        return step;
      // 将周围为访问过节点加入queue中，准备下一层一起访问
      for (Node x in cur.adj()) {
        if (x not in visited) {
          q.push(x);
          visited.add(x);
        }
      }
    }
    // 此处是一层的结束，所以step要加
    ++step;
  }
}
```

## Code

```cpp=
class Solution {
 public:
  int minDepth(TreeNode *root) {
    int step{};
    if (root == nullptr) return step;
    std::queue<TreeNode *> q{};
    q.push(root);
    ++step;
    while (!q.empty()) {
      int cur_level_size = q.size();
      for (int i{}; i < cur_level_size; ++i) {
        auto node = q.front();
        q.pop();
        if (node->right == nullptr && node->left == nullptr) return step;
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }
      ++step;
    }
    return step;
  }
};
```
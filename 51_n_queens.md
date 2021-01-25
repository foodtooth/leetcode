---
title: 51. N-Queens
tags: leetcode
---

https://leetcode.com/problems/n-queens/

## Idea

## Code

```cpp=
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result{};
    std::vector<std::string> cur(n, std::string(n, '.'));
    // to record placed row number
    std::vector<int> placed(n);
    //    std::size_t sn{static_cast<size_t>(n)};
    // we put queues all down the rows, so we only need to check upper area
    std::function<bool(int, int)> CheckUpperArea = [&](int row, int col) {
      // check upper left
      for (int i{row - 1}, j{col - 1}; i >= 0 && j >= 0; --i, --j) {
        if (cur[i][j] == 'Q') return false;
      }
      // check upper right
      for (int i{row - 1}, j{col + 1}; i >= 0 && j < n; --i, ++j) {
        if (cur[i][j] == 'Q') return false;
      }
      return true;
    };
    std::function<void(int)> dfs = [&](int l) {
      if (l == n) {
        result.push_back(cur);
        return;
      }
      for (int i{}; i < n; ++i) {
        if (placed[i] == 1) continue;
        if (!CheckUpperArea(l, i)) continue;
        placed[i] = 1;
        cur[l][i] = 'Q';
        dfs(l + 1);
        placed[i] = 0;
        cur[l][i] = '.';
      }
    };
    dfs(0);
    return result;
  }
};
```
---
title: 289. Game of Life
tags: leetcode
---

https://leetcode.com/problems/game-of-life/

## Idea

## Code

```cpp=
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    auto copy = board;
    auto row_size = board.size();
    if (board.empty()) return;
    auto column_size = board[0].size();
    for (int r{}; r < row_size; ++r) {
      for (int c{}; c < column_size; ++c) {
        board[r][c] = DeadOrLive(copy, r, c);
      }
    }
  }

 private:
  bool DeadOrLive(const std::vector<std::vector<int>>& board, int n, int m) {
    int lives{};
    auto row_size = board.size();
    auto column_size = board[0].size();
    auto go_up = n - 1 >= 0;
    auto go_down = n + 1 <= row_size - 1;
    auto go_left = m - 1 >= 0;
    auto go_right = m + 1 <= column_size - 1;
    if (go_up) {
      lives += board[n - 1][m];
      if (go_left) {
        lives += board[n - 1][m - 1];
      }
      if (go_right) {
        lives += board[n - 1][m + 1];
      }
    }
    if (go_down) {
      lives += board[n + 1][m];
      if (go_left) {
        lives += board[n + 1][m - 1];
      }
      if (go_right) {
        lives += board[n + 1][m + 1];
      }
    }
    if (go_left) {
      lives += board[n][m - 1];
    }
    if (go_right) {
      lives += board[n][m + 1];
    }
    if (board[n][m]) {
      if (lives < 2 || lives > 3)
        return false;
      else if (lives == 2 || lives == 3)
        return true;
    } else {
      if (lives == 3)
        return true;
      else
        return false;
    }
    return false;
  }
};
```
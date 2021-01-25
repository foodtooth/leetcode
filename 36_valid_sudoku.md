---
title: 36. Valid Sudoku
tags: leetcode
---

https://leetcode.com/problems/valid-sudoku/

## Idea

## Code

```cpp=
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int const sudoku_len{9};
    std::bitset<sudoku_len> checklist{};
    auto CheckRow = [&]() {
      for (int row{0}; row < sudoku_len; ++row) {
        checklist.reset();
        for (int col{0}; col < sudoku_len; ++col) {
          char c = board[row][col];
          if (c == '.') continue;
          int index = c - '0';
          --index;
          if (checklist[index]) return false;
          checklist.set(index);
        }
      }
      return true;
    };
    auto CheckCol = [&]() {
      for (int col{0}; col < sudoku_len; ++col) {
        checklist.reset();
        for (int row{0}; row < sudoku_len; ++row) {
          char c = board[row][col];
          if (c == '.') continue;
          int index = c - '0';
          --index;
          if (checklist[index]) return false;
          checklist.set(index);
        }
      }
      return true;
    };
    auto CheckBox = [&]() {
      int single = std::sqrt(sudoku_len);
      for (int i{0}; i < sudoku_len; ++i) {
        int ex_row = i / single;
        int ex_col = i % single;
        checklist.reset();
        for (int j{0}; j < sudoku_len; ++j) {
          int row = j / single;
          int col = j % single;
          char c = board[row + ex_row * single][col + ex_col * single];
          if (c == '.') continue;
          int index = c - '0';
          --index;
          if (checklist[index]) return false;
          checklist.set(index);
        }
      }
      return true;
    };
    if (CheckRow() && CheckCol() && CheckBox()) return true;
    return false;
  }
};
```
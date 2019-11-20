---
title: 794. Valid Tic-Tac-Toe State
tags: leetcode
---

https://leetcode.com/problems/valid-tic-tac-toe-state/

## Idea

## Code
```cpp
class Solution {
 public:
  bool validTicTacToe(vector<string> &board) {
    int count = 0;
    int xn{};
    int on{};
    std::vector<bool> xs(9, false);
    std::vector<bool> os(9, false);

    for (const auto &i : board) {
      for (auto j : i) {
        if (j == 'X') {
          xs[count] = true;
          ++xn;
        } else if (j == 'O') {
          os[count] = true;
          ++on;
        }
        ++count;
      }
    }
    if (!(xn == on || xn - on == 1)) return false;
    std::array<std::tuple<int, int, int>, 8> cheat_sheet{
        std::make_tuple(0, 1, 2), std::make_tuple(3, 4, 5),
        std::make_tuple(6, 7, 8), std::make_tuple(0, 3, 6),
        std::make_tuple(1, 4, 7), std::make_tuple(2, 5, 8),
        std::make_tuple(0, 4, 8), std::make_tuple(2, 4, 6)};
    int xc{};
    int oc{};

    for (const auto &i : cheat_sheet) {
      auto [x, y, z] = i;
      if (xs[x] && xs[y] && xs[z]) {
        ++xc;
      }
      if (os[x] && os[y] && os[z]) {
        ++oc;
      }
    }
    if (xc >= 1 && oc == 0 && xn - on == 1)
      return true;
    else if (xc == 0 && oc >= 1 && xn == on)
      return true;
    else if (xc == 0 && oc == 0)
      return true;
    else
      return false;
  }
};
```
---
title: 417. Pacific Atlantic Water Flow
tags: leetcode
---

https://leetcode.com/problems/pacific-atlantic-water-flow/

## Idea

## Code
1. DFS

    ```cpp=
    class Solution {
     public:
      vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        row_size_ = matrix.size();
        column_size_ = matrix[0].size();

        std::vector<std::vector<int>> unit_2_pacific(
            row_size_, std::vector<int>(column_size_));
        std::vector<std::vector<int>> unit_2_atlantic(
            row_size_, std::vector<int>(column_size_));
        std::vector<std::vector<int>> result{};

        for (int x = 0; x < column_size_; ++x) {
          DFS(matrix, 0, x, 0, unit_2_pacific);               // top
          DFS(matrix, row_size_ - 1, x, 0, unit_2_atlantic);  // bottom
        }

        for (int y = 0; y < row_size_; ++y) {
          DFS(matrix, y, 0, 0, unit_2_pacific);                  // left
          DFS(matrix, y, column_size_ - 1, 0, unit_2_atlantic);  // right
        }

        for (int i = 0; i < row_size_; ++i)
          for (int j = 0; j < column_size_; ++j)
            if (unit_2_atlantic[i][j] && unit_2_pacific[i][j])
              result.emplace_back(std::initializer_list<int>{i, j});

        return result;
      }

     private:
      int row_size_{};
      int column_size_{};

      void DFS(std::vector<std::vector<int>> &matrix, int y, int x, int height,
               std::vector<std::vector<int>> &checker) {
        if (x < 0 || x >= column_size_ || y < 0 || y >= row_size_) return;
        if (checker[y][x]) return;
        if (matrix[y][x] < height) return;
        checker[y][x] = 1;
        DFS(matrix, y - 1, x, matrix[y][x], checker);
        DFS(matrix, y, x + 1, matrix[y][x], checker);
        DFS(matrix, y + 1, x, matrix[y][x], checker);
        DFS(matrix, y, x - 1, matrix[y][x], checker);
      }
    };
    ```

2. DP
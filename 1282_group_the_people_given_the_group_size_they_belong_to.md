---
title: 1282. Group the People Given the Group Size They Belong To
tags: leetcode
---

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

## Idea

## Code
1. Straight forward

    ```cpp=
    class Solution {
     public:
      vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        std::vector<std::vector<int>> result{};
        std::unordered_map<int, std::vector<int>> count{};
        int index{0};
        for (auto size : groupSizes) {
          if (count[size].size() != size) {
            count[size].emplace_back(index);
          } else if (count[size].size() == size) {
            result.emplace_back(count[size]);
            count[size] = {index};
          }
          ++index;
        }
        for (auto [key, value] : count) {
          result.emplace_back(value);
        }
        return result;
      }
    };
    ```
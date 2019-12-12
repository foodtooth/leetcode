---
title: 881. Boats to Save People
tags: leetcode
---

https://leetcode.com/problems/boats-to-save-people/

## Idea

## Code
1. Straight forward

    ```cpp=
    class Solution {
     public:
      int numRescueBoats(vector<int> &people, int limit) {
        std::unordered_map<int, int> count{};
        for (auto one : people) {
          ++count[one];
        }
        std::sort(people.begin(), people.end(), std::greater());
        people.erase(std::unique(people.begin(), people.end()), people.end());
        int result{};
        while (!people.empty()) {
          ++result;
          auto remaining = limit - people[0];

          if (remaining > 0) {
            auto it = std::lower_bound(people.begin(), people.end(), remaining,
                                       std::greater());
            if (it != people.end()) {
              if (--count[*it] == 0) {
                people.erase(it);
              }
            }
          }

          if (--count[people[0]] == 0) {
            people.erase(people.begin());
          }
        }
        return result;
      }
    };
    ```
---
title: 621. Task Scheduler
tags: leetcode
---

https://leetcode.com/problems/task-scheduler/

## Idea

## Code

```cpp=
class Solution {
 public:
  int leastInterval(vector<char> &tasks, int n) {
    std::array<int, 26> count{};
    for (auto c : tasks) {
      count[c - 'A'] += 1;
    }
    std::priority_queue<int> pq{};
    for (auto i : count) {
      if (i != 0) {
        pq.push(i);
      }
    }
    int result{};
    auto cycle = n + 1;
    while (!pq.empty()) {
      int time{};
      std::vector<int> backup{};
      for (int i = 0; i < cycle; ++i) {
        if (!pq.empty()) {
          backup.emplace_back(pq.top());
          pq.pop();
          ++time;
        }
      }
      for (auto num : backup) {
        if (--num != 0) {
          pq.push(num);
        }
      }
      result += !pq.empty() ? cycle : time;
    }

    return result;
  }
};
```
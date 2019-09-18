---
title: 347. Top K Frequent Elements
tags: leetcode
---

https://leetcode.com/problems/top-k-frequent-elements/

## Idea

## Code
```cpp
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> u{};
    auto cmp = [&u](int left, int right) { return u[left] < u[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);

    for (const auto& n : nums) {
      u[n] += 1;
    }
    for (const auto& n : u) {
      q.push(n.first);
    }
    std::vector<int> r{};
    r.reserve(k);
    while (k-- != 0) {
      r.push_back(q.top());
      q.pop();
    }
    return r;
  }
};
```
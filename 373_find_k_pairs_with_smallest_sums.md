---
title: 373. Find K Pairs with Smallest Sums
tags: leetcode
---

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

## Idea
We can sort all of them in a priority_queue and pick.

## Code
Straight forward:
```cpp
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [](const std::vector<int>& left, const std::vector<int>& right) {
      return left.front() + left.back() < right.front() + right.back();
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        decltype(cmp)>
        pq(cmp);
    for (int i{}; i < nums1.size(); ++i) {
      for (int j{}; j < nums2.size(); ++j) {
        pq.emplace((std::initializer_list<int>){nums1[i], nums2[j]});
        if (pq.size() > k) pq.pop();
      }
    }
    std::vector<std::vector<int>> result;
    while (!pq.empty()) {
      result.push_back(pq.top());
      pq.pop();
    }
    return result;
  }
};
```
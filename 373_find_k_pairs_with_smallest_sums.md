---
title: 373. Find K Pairs with Smallest Sums
tags: leetcode
disqus: foodtooths-hackmd
---

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

## Idea
We can sort all of them in a priority_queue and pick.

### Smart one
由于全量的排序操作，元素移位操作等损耗很大。针对这$m \times n$对数的排列（这个矩阵），可以直接考虑出方法找出当前候选值中的小值，然后往复到结束条件。

## Code
### Straight forward
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

### Smart one
```cpp
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    int nums1_size = nums1.size();
    int nums2_size = nums2.size();

    std::vector<std::vector<int>> result{};
    if (nums1_size == 0 || nums2_size == 0) return result;

    // Comparision func for cands(extract index from tuple and compare sum)
    auto cmp = [&nums1, &nums2](auto left, auto right) {
      return nums1[std::get<0>(left)] + nums2[std::get<1>(left)] >
             nums1[std::get<0>(right)] + nums2[std::get<1>(right)];
    };
    std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>,
                        decltype(cmp)>
        cands(cmp);

    // Checkers are used to check whether there is smaller one already in cands
    std::vector<bool> x_checker(nums1_size, false);
    std::vector<bool> y_checker(nums2_size, false);

    int x{}, y{};
    while (true) {
      if (k == 0 || (x + 1 == nums1_size && y + 1 == nums2_size)) {
        return result;
      }
      // Handle first-one condition
      if (cands.empty()) {
        cands.emplace(x, y);
        x_checker[x] = true;
        y_checker[y] = true;
      }

      // Get current smallest sum one
      std::tie(x, y) = cands.top();
      cands.pop();
      x_checker[x] = false;
      y_checker[y] = false;
      result.emplace_back(std::initializer_list<int>{nums1[x], nums2[y]});
      --k;

      // Push new candidates according to popped one
      if (x + 1 < nums1_size && !x_checker[x + 1]) {
        cands.emplace(x + 1, y);
        x_checker[x + 1] = true;
        y_checker[y] = true;
      }
      if (y + 1 < nums2_size && !y_checker[y + 1]) {
        cands.emplace(x, y + 1);
        x_checker[x] = true;
        y_checker[y + 1] = true;
      }
    }
  }
};
```
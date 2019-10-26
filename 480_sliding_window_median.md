---
title: 480. Sliding Window Median
tags: leetcode
---

https://leetcode.com/problems/sliding-window-median/

## Idea

## Code
```cpp
class Solution {
 public:
  // Noting that this function can be shorten to an one-line statement.
  // We should compare the selected middle one and upcoming one, and it
  // determines how to move mid pointer to next.
  template <typename Iterator>
  double getMedian(Iterator first, int n) {
    if (n % 2 == 0) {
      return (static_cast<long>(*std::next(first, n / 2 - 1)) +
              static_cast<long>(*std::next(first, n / 2))) /
             2.0;
    } else {
      return *std::next(first, (n - 1) / 2);
    }
  }

  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    std::multiset<int> window{nums.begin(), std::next(nums.begin(), k)};
    int n_size = nums.size();
    std::vector<double> result{};
    result.emplace_back(getMedian(window.begin(), k));
    for (int i = 1; i < n_size - k + 1; ++i) {
      auto it = window.find(nums[i - 1]);
      window.erase(it);
      window.insert(nums[i + k - 1]);
      result.emplace_back(getMedian(window.begin(), k));
    }
    return result;
  }
};
```
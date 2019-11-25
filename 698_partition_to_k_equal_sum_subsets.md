---
title: 698. Partition to K Equal Sum Subsets
tags: leetcode
---

https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

## Idea
细读题意后发现，这就像是所有的数字随机分配到某一个盒子中，最后查看是否符合条件。代码中这个分配的过程，通过对每个数字递归放置的方法实现。

```txt=
# 对一个数是否能够放置是递归中完整的一轮
bool PutNumber(current_index):
    for current_bucket in buckets:
        try putting
            if ok:
                try PutNumber(next_index)
            else:
                try next bucket
    return false # buckets do not fit
```

## Code
```cpp
class Solution {
 public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    target_ = sum / k;
    buckets_ = std::move(std::vector<int>(k, 0));
    std::sort(nums.begin(), nums.end(), std::greater<>());
    if (!nums.empty() && nums[0] > target_) return false;
    nums_ = std::move(nums);
    return put(0);
  }

 private:
  int target_{};
  std::vector<int> buckets_{};
  std::vector<int> nums_{};

  bool put(int i) {
    int buckets_size = buckets_.size();
    int nums_size = nums_.size();
    for (int j = 0; j < buckets_size; ++j) {
      if (buckets_[j] + nums_[i] <= target_) {
        // This bucket fits
        buckets_[j] += nums_[i];
      } else {
        // Try next bucket
        continue;
      }
      // We have fit the last number into buckets, so succeed
      if (i == nums_size - 1) {
        return true;
      }
      // Try putting next number
      if (put(i + 1)) {
        return true;
      } else {
        // Can not put next one, so current one is wrong. Take it out
        buckets_[j] -= nums_[i];
      }
    }
    // No bucket fits
    return false;
  }
};
```
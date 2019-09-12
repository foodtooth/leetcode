---
title: 324. Wiggle Sort II
tags: leetcode
---

https://leetcode.com/problems/wiggle-sort-ii/

## Idea
### For Wiggle Sort I
Given an unsorted array `nums`, reorder it **in-place** such that `nums[0] <= nums[1] >= nums[2] <= nums[3]...`.

#### Straight forward
If we have a sorted array as `nums[0] <= nums[1] <= nums[2] <= ...`,

$$\begin{align}
& \because nums[0] \leq nums[1] \leq nums[2] \\
& \therefore nums[0] \leq nums[2] \\
\end{align}$$

we can get a valid solution $nums[0] \leq nums[2] \geq nums[1] \leq nums[4] \geq \ldots$ by just swapping `nums[2i + 1]` and `nums[2i + 2]`.

#### Smart one
The adjacent numbers' order currently we have is what we need to care about, and swapping them will not change the order of the last pair.

### For Wiggle Sort II
#### Straight forward
How to find the possibly only one valid answer? Think about inputs like $1, 2, 2, 4$ or $1, 1, 1, 2, 2$.  
上述例子容易看出不能再使用greedy solution，否则可能会找不到唯一解。我们把任意正确解用线图简单连接后不难发现，实质上一定要有上面一层，比对应下面一层的每个对应数都大一些，否则不会有正确解。所以考虑再对数组排序后，分为两部分在其中从大开始抽取数据(因为上述第一个例子中的情况，必须从大开始选，以满足小数列中能优先选取到大数的情况)。

## Code
#### Straight forward
```cpp
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    bool is_odd = size % 2 == 1;
    auto mid = std::next(nums.begin(), is_odd ? size / 2 + 1 : size / 2);
    std::vector<int> v1(nums.begin(), mid);
    std::vector<int> v2(mid, nums.end());
    std::vector<int> r{};
    int fixed = is_odd ? 1 : 0;
    int i = size / 2 - 1 + fixed;
    for (; i - fixed >= 0; --i) {
      r.push_back(v1[i]);
      r.push_back(v2[i - fixed]);
    }
    if (is_odd) r.push_back(v1[0]);
    nums = r;
  }
};
```
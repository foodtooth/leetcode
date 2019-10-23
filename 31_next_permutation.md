https://leetcode.com/problems/next-permutation/

## Idea
### Straight forward
1. Reverse find the first pair that has descending order (`r_it + 1`, `r_it`)
2. Swap `r_it + 1` with the first one bigger than it in range `[rbegin, r_it + 1)` 
3. Swap the whole sequence behind `r_it` (if exist)

## Code
### Straight forward
```cpp
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    auto it = nums.rbegin();
    for (; it + 1 < nums.rend(); ++it) {
      if (*(it + 1) < *it) {
        std::iter_swap(
            std::find_if(nums.rbegin(), it + 1,
                         [&it](const int& item) { return *(it + 1) < item; }),
            it + 1);
        break;
      }
    }
    if (it != nums.rbegin()) {
      std::reverse(nums.rbegin(), it + 1 <= nums.rend() ? it + 1 : nums.rend());
    }
  }
};
```
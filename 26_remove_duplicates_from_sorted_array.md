https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## Idea

## Code

```cpp
#include <limits>
#include <algorithm>

class Solution {
 public:
  // Brute force
  int removeDuplicates(vector<int>& nums) {
    int previous = std::numeric_limits<int>::max();
    for (auto it = nums.begin(); it != nums.end();) {
      if (*it != previous) {
        previous = *it;
        ++it;
      } else {
        it = nums.erase(it);
      }
    }

    return nums.size();
  }

  // Use C++11 algorithm
  int removeDuplicates2(vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
  }
};
```
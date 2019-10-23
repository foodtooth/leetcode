https://leetcode.com/problems/remove-element/

## Idea
几个提示点要用到。in-place要求，可以通过数组中的window方式，采用两个pointer遍历。

## Code

### Straight forward one
```cpp
#include <algorithm>

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    std::sort(nums.begin(), nums.end());
    auto it = nums.begin();
    for (; it != nums.end(); ++it) {
      if (val != *it) {
        continue;
      } else {
        break;
      }
    }

    if (it != nums.end()) {
      auto second = it;
      ++second;
      for (; second != nums.end(); ++second) {
        if (*second != val) {
          break;
        }
      }
      nums.erase(it, second);
    }
    return nums.size();
  }
};
```

### Two pointers
```cpp
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i{0};
    int j{0};
    const auto kSize = nums.size();
    for (; j < kSize; ++j) {
      if (nums[j] == val) {
        continue;
      } else {
        nums[i] = nums[j];
        ++i;
      }
    }
    return i;
  }
};
```

### Smart One
Using [`std::distance`](https://en.cppreference.com/w/cpp/iterator/distance), [`std::remove`](https://en.cppreference.com/w/cpp/algorithm/remove).

```cpp
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    return std::distance(nums.begin(),
                         std::remove(nums.begin(), nums.end(), val));
  }
};
```
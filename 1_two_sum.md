https://leetcode.com/problems/two-sum/

## Code

```cpp
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> m;
    std::vector<int> result;
    for (int index = 0; index < nums.size(); ++index) {
      int key = nums[index];
      int another_key = target - nums[index];
      if (m.find(another_key) != m.end()) {
        result.push_back(m[another_key]);
        result.push_back(index);
        return result;
      }
      m[key] = index;
    }
    return result;
  }
};
```

```python
#!/usr/bin/env python3
# coding: utf-8


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(length):
            for j in range(i + 1, length):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def twoSum2(self, nums, target):
        diff_dict = {}
        for i, num in enumerate(nums):
            if num in diff_dict.keys():
                return [diff_dict[num], i]
            else:
                diff_dict[target - num] = i


def main():
    pass


if __name__ == '__main__':
    main()
```
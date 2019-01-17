/*
 * https://leetcode.com/problems/two-sum/
 */

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

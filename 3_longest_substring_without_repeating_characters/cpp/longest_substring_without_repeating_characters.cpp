/*
 * longest_substring_without_repeating_characters.cpp
 *
 *  Created on: Jan 17, 2019
 *      Author: dx
 */

#include <unordered_set>
#include <algorithm>

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int len = s.size();
    int i = 0;
    int j = i;
    std::unordered_set<char> cs { };
    int result = 0;

    while (i < len && j < len) {
      if (cs.find(s[j]) == cs.end()) {
        result = std::max(result, j + 1 - i);
        cs.insert(s[j]);
        ++j;
      } else {
        cs.erase(s[i]);
        ++i;
      }
    }

    return result;
  }
};

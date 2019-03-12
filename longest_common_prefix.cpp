/*
 * longest_common_prefix.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: dx
 */

#include <string>

class Solution {
 public:
  // 比普通比较减少次数，通过Binary Search
  string longestCommonPrefix(vector<string>& strs) {
  }

  string longestCommonPrefix2(vector<string>& strs) {
    int words_count = strs.size();
    int word_len = words_count != 0 ? strs[0].size() : 0;
    std::string result = words_count == 1 ? strs[0] : "";

    for (int i { }; i < word_len; ++i) {
      for (int j { 1 }; j < words_count; ++j) {
        if (strs[j][i] == strs[0][i]) {
          if (j == words_count - 1) {
            result.push_back(strs[0][i]);
          }
          continue;
        } else {
          return result;
        }
      }
    }
    return result;
  }
};

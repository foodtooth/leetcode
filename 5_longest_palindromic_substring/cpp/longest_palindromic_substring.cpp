/*
 * longest_palindromic_substring.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: dx
 */

#include <string>

class Solution {
 public:
  // 奇数序列及偶数序列分别判断
  string longestPalindrome(string s) {
    // Init using input. Default result when palindrome is a single char
    std::string result { s[0] };
    int max { };
    int start { };
    int len = s.size();
    int odd { };
    int left { }, right { };

    max = 0;
    odd = 0;
    while (odd <= 1) {
      start = 0;
      while (start < len) {
        left = start, right = start + 1 + odd;
        while (left >= 0 && right < len) {
          if (s[left] == s[right]) {
            if ((right - left + 1) > max) {
              max = right - left + 1;
              result = s.substr(left, max);
            }
            --left;
            ++right;
          } else {
            break;
          }
        }
        ++start;
      }
      ++odd;
    }

    return result;
  }

  // DP. Brute Force.
  string longestPalindrome2(string s) {
    int i { 0 };
    int j { i + 1 };
    int len = s.size();
    int max { 0 };
    std::string result { s[0] };

    while (i < len) {
      while (j < len) {
        if (isP(s, i, j)) {
          if (j - i + 1 > max) {
            max = j - i + 1;
            result = s.substr(i, max);
          }
        }
        ++j;
      }
      ++i;
      j = i + 1;
    }
    return result;
  }
  bool isP(const std::string &s, int i, int j) {
    if (i < j)
      return ((s[i] == s[j]) && isP(s, i + 1, j - 1));
    else
      return true;
  }
};

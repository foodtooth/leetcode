/*
 * zigzag_conversion.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: dx
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  // A math problem
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    else {
      int row { 0 };
      int index { };
      int len = s.size();
      std::string result { };
      while (row < numRows) {
        index = row;
        if (index >= len) {
          break;
        }
        while (index < len) {
          result.push_back(s[index]);
          if (!(row == 0 || row == numRows - 1)) {
            int j = index + (numRows - row - 1) * 2;
            if (j < len) {
              result.push_back(s[j]);
            } else {
              break;
            }
          }
          index = index + 2 * (numRows - 1);
        }
        ++row;
      }
      return result;
    }
  }

  // Use multi-dimen vector. Regular approach
  string convert2(string s, int numRows) {
    if (numRows > 1) {
      std::vector<std::vector<int>> data { };

      int row = 0;
      while (row < numRows) {
        data.push_back( { });
        ++row;
      }

      row = 0;
      int i = 0;
      int len = s.size();
      int column = 0;
      int direction = 0;  // 0 for down, 1 for up
      while (i < len) {
        if (row == 0 || row == (numRows - 1)) {
          data[row].push_back(s[i]);
          ++i;
          if (row == 0) {
            direction = 0;
            ++row;
          } else {
            direction = 1;
            --row;
          }
        } else {
          if (direction == 0) {
            data[row].push_back(s[i]);
            ++i;
            ++row;
          } else {
            for (int j = 0; j < numRows; ++j) {
              if (j == row) {
                data[j].push_back(s[i]);
                ++i;
              } else {
                data[j].push_back(0);
              }
            }
            --row;
          }
        }
      }

      // Create result from data
      std::string result { };
      for (auto &x : data) {
        for (auto &y : x) {
          if (y != 0) {
            result.push_back(y);
          }
        }
      }

      return result;
    } else {
      return s;
    }
  }
};

https://leetcode.com/problems/string-to-integer-atoi/

## Code

```cpp
#include <cstdio>
#include <cstdint>

class Solution {
 public:
  int myAtoi(string str) {
    bool number_starts = false;
    bool need_negative = false;
    int result { 0 };

    for (const char &i : str) {
      if (!number_starts) {
        if (i == ' ') {
          continue;
        } else if (i == '+' || i == '-') {
          number_starts = true;
          need_negative = i == '+' ? false : true;
        } else if (i <= '9' && i >= '0') {
          number_starts = true;
          result = i - '0';
        } else {
          break;
        }
      } else {
        if (i <= '9' && i >= '0') {
          if (result >= 0) {
            if (!(result <= INT32_MAX / 10
                && result * 10 <= INT32_MAX - (i - '0'))) {
              result = INT32_MAX;
              break;
            }
            result = result * 10 + (i - '0');
          }
          if (result < 0) {
            if (!(result >= INT32_MIN / 10
                && result * 10 >= INT32_MIN + (i - '0'))) {
              result = INT32_MIN;
              break;
            }
            result = result * 10 - (i - '0');
          }

          if (need_negative && result != 0) {
            result = -result;
            need_negative = false;
          }
        } else {
          break;
        }
      }
    }

    return result;
  }
};
```
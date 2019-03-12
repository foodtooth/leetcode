https://leetcode.com/problems/integer-to-roman/

## Code

```cpp
#include <string>
#include <vector>

class Solution {
 public:
  string intToRoman(int num) {
    std::string result { };
    int cur { };
    int level { };
    std::vector<char> ones { 'I', 'X', 'C', 'M' };
    std::vector<char> fives { 'V', 'L', 'D' };
    while (num != 0) {
      cur = num % 10;

      if (cur != 0) {
        if (cur < 4) {
          result.insert(0, cur, ones[level]);
        } else if (cur == 4) {
          result.insert(0, 1, fives[level]);
          result.insert(0, 1, ones[level]);
        } else if (cur == 5) {
          result.insert(0, 1, fives[level]);
        } else if (cur < 9) {
          result.insert(0, cur - 5, ones[level]);
          result.insert(0, 1, fives[level]);
        } else if (cur == 9) {
          result.insert(0, 1, ones[level + 1]);
          result.insert(0, 1, ones[level]);
        }
      }

      ++level;
      num /= 10;
    }

    return result;
  }
};
```
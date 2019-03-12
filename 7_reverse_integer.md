https://leetcode.com/problems/reverse-integer/

## Code

```cpp
#include <cstdint>
#include <cinttypes>

class Solution {
 public:
  int reverse(int x) {
    std::int32_t result { 0 };
    int pop { };
    while (x != 0) {
      if (result > 0 && result > INT32_MAX / 10) {
        return 0;
      }
      if (result < 0 && result < INT32_MIN / 10) {
        return 0;
      }
      pop = x % 10;
      result = result * 10 + pop;
      x /= 10;
    }
    return result;
  }
};
```
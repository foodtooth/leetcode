https://leetcode.com/problems/palindrome-number/

## Code

```cpp
#include <string>

class Solution {
 public:
  bool isPalindrome(int x) {
    int reversed { 0 };
    bool result { true };

    if (x < 0 || x % 10 == 0)
      result = false;
    else {
      while (x > reversed) {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
      }
    }

    if (x == reversed || x == reversed / 10)
      result = true;
    else
      result = false;

    return result;
  }

  // Simple way
  bool isPalindrome2(int x) {
    std::string y { };

    if (x < 0)
      return false;

    bool result { true };

    while (x != 0) {
      y.push_back(x % 10);
      x = x / 10;
    }

    int length = y.size();
    for (int i = 0; i < length / 2; ++i) {
      if (y[i] != y[length - i - 1])
        result = false;
    }

    return result;
  }
};
```
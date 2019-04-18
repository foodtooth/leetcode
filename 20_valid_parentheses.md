https://leetcode.com/problems/valid-parentheses/

## Idea

## Code

```cpp
#include <unordered_set>
#include <stack>

class Solution {
 public:
  bool isValid(string s) {
    std::unordered_map<char, char> pair { { '(', ')' }, { '{', '}' },
        { '[', ']' } };

    std::stack<char> t;

    for (auto &a : s) {
      if (pair.find(a) != pair.end()) {
        t.push(a);
      } else {
        if (t.empty())
          return false;
        else {
          if (a == pair[t.top()])
            t.pop();
          else
            return false;
        }
      }
    }

    if (t.empty())
      return true;
    else
      return false;
  }
};
```
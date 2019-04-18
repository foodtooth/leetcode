https://leetcode.com/problems/generate-parentheses/

## Idea
[Catalan number](https://en.wikipedia.org/wiki/Catalan_number)

### Backtracking
在一个recursion中，遍历依次在每个位置添加两个可能值，并且在达到规定长度后进行判断的方法（值得注意的一眼看下去不那么清晰的）
```python
def generate(A=[]):
    if len(A) == 2 * n:
        if valid(A):
            ans.append("".join(A))
    else:
        A.append('(')
        generate(A)
        A.pop()
        A.append(')')
        generate(A)
        A.pop()
```

Backtracking方法，可以在这个思路上，进行更多的剪枝操作。

### Closure number
[Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics))

[Disjoint sets](https://en.wikipedia.org/wiki/Disjoint_sets)

The "Closure number" approach which I don not really understand from leetcode official solutions. Which exactly is "Closure number" after all?

## Code

```cpp
#include <vector>
#include <string>

class Solution {
 public:
  // Backtracking using recursion
  vector<string> generateParenthesis(int n) {
    process("", n, n);
    return result;
  }

  void process(std::string x, int left_remaining, int right_remaining) {
    if (left_remaining == 0 && right_remaining == 0) {
      result.push_back(x);
    }
    if (left_remaining > 0) {
      process(x + "(", left_remaining - 1, right_remaining);
    }
    if (right_remaining > left_remaining) {
      process(x + ")", left_remaining, right_remaining - 1);
    }
  }

  std::vector<string> result { };
};
```
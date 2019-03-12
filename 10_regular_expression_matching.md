https://leetcode.com/problems/regular-expression-matching/

## Code

```cpp
class Solution {
 public:
  // DP
  bool isMatch(string s, string p) {
    int target_len = s.size();
    int regex_len = p.size();
    std::vector<std::vector<bool>> memo(
        target_len + 1, std::vector<bool>(regex_len + 1, false));

    // memo[i][j]: s[i:] matches p[j:] or not
    memo[target_len][regex_len] = true;

    // 其它部分都是很顺利的流程，值得额外注意的是下面两点（容易导致某些用例错误的，边界值确认和额外条件值）
    // 1. 为什么target循环还要从target_len开始，而regex循环从regex_len - 1开始。
    // 为了配合下面第二点做target被slice到空字符串时候的判断
    for (int i = target_len; i >= 0; --i) {
      for (int j = regex_len - 1; j >= 0; --j) {
        // 2. 为什么需要从原匹配条件之外，额外添加`i < target_len`的判断。
        // 为了做target被slice到最后空字符串时候的判断
        bool cur_match = i < target_len && (p[j] == s[i] || p[j] == '.');

        if (j + 1 < regex_len && p[j + 1] == '*') {
          memo[i][j] = memo[i][j + 2] || (cur_match && memo[i + 1][j]);
        } else {
          memo[i][j] = cur_match && memo[i + 1][j + 1];
        }
      }
    }

    return memo[0][0];
  }

  // Intuitive recursive way
  bool isMatch2(string s, string p) {
    // Using regex part to check emtpy
    if (p.empty()) {
      return s == p;
    }

    // Check first character
    bool first_match = !s.empty() && ((p[0] == s[0]) || (p[0] == '.'));

    // Check if current character follows an Kleene star
    if (p.size() >= 2 && p[1] == '*') {
      // Star follows. We may ignore this part of the pattern, or delete a
      // matching character in the text. And matching the remaining part.
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    } else {
      // A normal matching process
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};
```
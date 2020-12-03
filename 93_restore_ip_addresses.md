---
title: 93. Restore IP Addresses
tags: leetcode
---

https://leetcode.com/problems/restore-ip-addresses/

## Idea
DFS (or Backtracking)

## Code

```cpp=
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    Dsf(s, 0, "");
    return result;
  }

 private:
  void Dsf(const std::string s, int level, const std::string res) {
    if (level == 4) {
      if (s.empty()) {
        result.push_back(res.substr(0, res.size() - 1));
      }
      return;
    }
    for (int i{}; i < s.size(); ++i) {
      auto ss = s.substr(0, i + 1);
      auto n = std::stoi(ss);
      if (ss.size() > 3) {
        break;
      } else if (ss == "0" || (ss[0] != '0' && n <= 255 && n > 0)) {
        Dsf(s.substr(i + 1), level + 1, res + ss + ".");
      }
    }
  }

  std::vector<std::string> result{};
};
```
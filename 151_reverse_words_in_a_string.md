https://leetcode.com/problems/reverse-words-in-a-string/

## Idea

## Code
### Straight forward one
```cpp
class Solution {
 public:
  string reverseWords(string s) {
    std::vector<std::string> t;
    split(s, t);
    if (t.empty()) {
      return "";
    } else {
      std::string r{t.back()};
      for (auto it = t.rbegin() + 1; it < t.rend(); ++it) {
        r += " " + *it;
      }
      return r;
    }
  }

 private:
  static void split(const std::string& s, std::vector<std::string>& tokens,
                    const char delimiter = ' ') {
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
      if (!token.empty()) {
        tokens.push_back(token);
      }
    }
  }
};
```

### Others
1. You can first reverse the whole string, and then reverse each word of it.
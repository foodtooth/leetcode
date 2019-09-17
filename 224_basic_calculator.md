---
title: 224. Basic Calculator
tags: leetcode
---

https://leetcode.com/problems/basic-calculator/

## Idea

## Code
Straight forward using `recursion`:
```cpp
class Solution {
 public:
  int calculate(string s) {
    std::stack<char> pile;
    pile.push('+');
    int result{};
    std::string temp{};
    int counter{};
    for (const auto &i : s) {
      if (counter != 0) {
        if (i != ')') {
          temp.push_back(i);
          if (i == '(') {
            ++counter;
          }
        } else {
          --counter;
          if (counter != 0) {
            temp.push_back(i);
          } else {
            pile.pop();
            pile.push(')');
          }
        }
      } else {
        if (i == ' ') {
          continue;
        } else if (i == '(') {
          pile.push('(');
          ++counter;
        } else if (i == ')') {
          if (pile.top() == '(') {
            pile.pop();
            pile.push(')');
          }
        } else if (i == '+' || i == '-') {
          if (pile.top() == ')') {
            pile.pop();
            process(result, pile.top(), calculate(temp));
            pile.pop();  // pop last operator
            temp.clear();
            pile.push(i);
          } else {
            process(result, pile.top(), std::stoi(temp));
            pile.pop();
            temp.clear();
            pile.push(i);
          }
        } else {
          temp.push_back(i);
        }
      }
    }

    if (!pile.empty()) {
      if (pile.top() == ')') {
        pile.pop();
        process(result, pile.top(), calculate(temp));
      } else {
        process(result, pile.top(), std::stoi(temp));
      }
    }
    return result;
  }

  void process(int &result, const char &opt, const int &input) {
    if (opt == '+') {
      result += input;
    } else if (opt == '-') {
      result -= input;
    }
  }
};
```
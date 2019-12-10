---
title: 842. Split Array into Fibonacci Sequence
tags: leetcode
---

https://leetcode.com/problems/split-array-into-fibonacci-sequence/

## Idea

## Code
1. Straight forward

    前两个数字需要穷举，后面所有的数都要符合规律，验证通过即是OK，不通过则继续下一个穷举。

    ```cpp=
    class Solution {
     public:
      vector<int> splitIntoFibonacci(string S) {
        auto s_len{S.length()};

        for (int first_len{1}; first_len <= s_len / 2; ++first_len) {
          for (int second_len{1};
               std::max(first_len, second_len) <= s_len - first_len - second_len;
               ++second_len) {
            int last{first_len + second_len};

            auto sub1 = S.substr(0, first_len);
            auto sub2 = S.substr(first_len, second_len);

            if (sub1[0] == '0' && first_len > 1) return {};
            int a{};
            int b{};
            try {
              a = std::stoi(sub1);
              b = std::stoi(sub2);
            } catch (const std::out_of_range &e) {
              continue;
            }

            std::vector<int> result{a, b};

            std::vector<int> remaining{};
            bool alright{false};
            while (last < s_len) {
              if (std::numeric_limits<int>::max() - a < b) break;
              auto c = a + b;
              auto c_str = std::to_string(c);
              auto c_strlen = c_str.length();
              if (last + c_strlen > s_len) break;
              if (c_str == S.substr(last, c_strlen)) {
                remaining.emplace_back(c);
                last += c_strlen;
                a = b;
                b = c;
              } else {
                break;
              }
              if (last == s_len) alright = true;
            }
            if (alright) {
              std::move(remaining.begin(), remaining.end(),
                        std::back_inserter(result));
              return result;
            }
          }
        }
        return {};
      }
    };
    ```

1. jklk 
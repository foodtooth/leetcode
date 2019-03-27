https://leetcode.com/problems/letter-combinations-of-a-phone-number/

## Idea
[Backtracking(回溯法)](https://en.wikipedia.org/wiki/Backtracking)

> 对于某些计算问题而言，回溯法是一种可以找出所有（或一部分）解的一般性算法，尤其适用于约束满足问题（在解决约束满足问题时，我们逐步构造更多的候选解，并且在确定某一部分候选解不可能补全成正确解之后放弃继续搜索这个部分候选解本身及其可以拓展出的子候选解，转而测试其他的部分候选解）。

在这个例子中，回溯通过递归完成。合法结果的判断，是通过“达到指定长度的组合”。达到合法结果后，回溯到上一个待验证值。也可以用Tree traversal的方式表达，见leetcode链接中Solution里的描述和一些评论的解释。

## Code

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}

        def backtrack(combination: str, remaining: str) -> None:
            if remaining:
                for c in phone[remaining[0]]:
                    backtrack(combination + c, remaining[1:])
            else:
                output.append(combination)

        output = []
        if digits:
            backtrack('', digits)
        return output
```
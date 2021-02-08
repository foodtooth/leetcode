---
title: 876. Middle of the Linked List
tags: leetcode
---

https://leetcode.com/problems/middle-of-the-linked-list/

## Idea

双指针。快慢指针。

## Code

```cpp=
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *fast{head}, *slow{head};
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
```
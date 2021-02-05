---
title: 141. Linked List Cycle
tags: leetcode
---

https://leetcode.com/problems/linked-list-cycle/

## Idea

双指针。快慢指针。如果有环，快的最终会追上慢的（套圈了）。

## Code

```cpp=
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *fast{head}, *slow{head};
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }
    return false;
  }
};
```
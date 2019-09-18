---
title: 206. Reverse Linked List
tags: leetcode
---

https://leetcode.com/problems/reverse-linked-list/

## Idea

## Code
Iterative:
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    while (cur != NULL) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};
```
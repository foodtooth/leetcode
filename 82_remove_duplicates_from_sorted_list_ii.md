---
title: 82. Remove Duplicates from Sorted List II
tags: leetcode
---

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

## Idea

## Code
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode* vice_head = NULL;
    ListNode* pre = NULL;
    while (head != NULL && head->next != NULL) {
      if (head->val == head->next->val) {
        do {
          head = head->next;
        } while (head->next != NULL && head->val == head->next->val);
      } else {
        if (vice_head == NULL) {
          vice_head = head;
        }
        if (pre == NULL) {
          pre = head;
        } else {
          pre->next = head;
          pre = pre->next;
        }
      }
      head = head->next;
    }
    if (vice_head == NULL && head != NULL) {
      vice_head = head;
    }
    if (pre != NULL) {
      pre->next = head;
    }
    return vice_head;
  }
};
```
---
title: 83. Remove Duplicates from Sorted List
tags: leetcode
---

https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* vice_head = head;
    while (head->next != NULL) {
      if (head->val == head->next->val) {
        head->next = head->next->next;
      } else {
        head = head->next;
      }
    }
    return vice_head;
  }
};
```
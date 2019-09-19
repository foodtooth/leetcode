---
title: 92. Reverse Linked List II
tags: leetcode
---

https://leetcode.com/problems/reverse-linked-list-ii/

## Idea

## Code
Iterative(需要尽力考虑边界问题，统一遍历流程):
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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) {
      return head;
    }
    ListNode* leader = NULL;
    ListNode* vice_leader = head;
    if (m != 1) {
      int count{2};
      while (count++ != m) {
        head = head->next;
      }
      leader = head;
      head = head->next;
    }
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    int count{-1};
    while (cur != NULL && count != n - m) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
      ++count;
    }
    if (leader != NULL) {
      leader->next->next = next;
      leader->next = pre;
    } else {
      vice_leader->next = next;
      vice_leader = pre;
    }
    return vice_leader;
  }
};
```
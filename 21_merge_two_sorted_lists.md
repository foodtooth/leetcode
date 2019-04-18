https://leetcode.com/problems/merge-two-sorted-lists/

## Idea
Recursion和Iteration的转换，可以练习

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
  // Recursion
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }

  // Iteration
  ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;
    ListNode *head = NULL, *end = NULL;
    if (l1->val <= l2->val)
      head = l1;
    else
      head = l2;

    ListNode *next_l1, *next_l2;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val == l2->val) {
        if (end != NULL)
          end->next = l1;
        next_l1 = l1->next;
        next_l2 = l2->next;
        l1->next = l2;
        end = l2;

        // prepare for next loop
        l1 = next_l1;
        l2 = next_l2;
      } else if (l1->val < l2->val) {
        if (end != NULL)
          end->next = l1;
        end = l1;
        l1 = l1->next;
      } else {
        if (end != NULL)
          end->next = l2;
        end = l2;
        l2 = l2->next;
      }
    }

    if (l1 != NULL)
      end->next = l1;
    if (l2 != NULL)
      end->next = l2;

    return head;
  }
};
```
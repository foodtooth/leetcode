https://leetcode.com/problems/reverse-nodes-in-k-group/

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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
      return head;
    }

    ListNode *tmp_head { NULL };
    ListNode *next_2_k { NULL };
    ListNode *last { NULL };
    ListNode *target { NULL };
    ListNode *waiting { NULL };
    int count { 0 };

    tmp_head = head;
    while (tmp_head != NULL) {
      ++count;
      if (count == k) {
        break;
      }
      tmp_head = tmp_head->next;
    }

    if (count == k) {
      next_2_k = tmp_head->next;
    } else {
      return head;
    }

    tmp_head = head;
    last = head;
    count = 1;
    target = tmp_head->next;

    while (k - count >= 2) {
      waiting = target->next;
      target->next = tmp_head;
      tmp_head = target;
      ++count;
      target = waiting;
    }
    waiting = target->next;
    target->next = tmp_head;
    tmp_head = target;
    head->next = reverseKGroup(waiting, k);

    return tmp_head;
  }
};
```
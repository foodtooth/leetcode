https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## Idea
只能单向走，所以要在这个过程中做到track n-th item from end，同时保存后续操作需要用到的item。

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *target = head;
    ListNode *it = head;
    ListNode *before_target = NULL;

    while (it != NULL) {
      // Handle current loop
      if (n != 0) {
        // Skip n-length list, to track n-th item from end
        --n;
      } else {
        before_target = target;
        target = target->next;
      }

      // Prepare for next loop
      it = it->next;
    }

    if (before_target == NULL) {
      return target->next;
    } else {
      before_target->next = target->next;
      return head;
    }
  }
};
```
https://leetcode.com/problems/swap-nodes-in-pairs/

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
  // Recursion
  ListNode* swapPairs(ListNode* head) {
    ListNode *tmp_head { NULL };
    ListNode *third { NULL };
    if (head != NULL && head->next != NULL) {
      tmp_head = head;
      head = head->next;
      third = head->next;
      head->next = tmp_head;
      tmp_head->next = swapPairs(third);
    }

    return head;
  }
};
```
https://leetcode.com/problems/add-two-numbers/

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(0);
    ListNode *head = result;
    int carry = 0;
    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }

      if (result) {
        result->val = carry % 10;
      }
      carry /= 10;
      if (l1 || l2 || carry) {
        result->next = new ListNode(0);
        result = result->next;
      }
    }
    return head;
  }

  ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    carry /= 10;
    if (!l1 && !l2 && !carry) {
      return nullptr;
    }
    ListNode *result = new ListNode(0);

    if (l1) {
      carry += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      carry += l2->val;
      l2 = l2->next;
    }
    if (result) {
      result->val = carry % 10;
      result->next = addTwoNumbers(l1, l2);
    }

    return result;
  }
  int carry { 0 };
};
```
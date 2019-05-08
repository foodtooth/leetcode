https://leetcode.com/problems/merge-k-sorted-lists/

## Idea
### Brute Force
把所有数值放在一个array中，进行sort，然后放在linked list里，返回即可。

### 每次比较所有list中的当前值
比较拿出最小的放入要返回的linked list中，同时被拿出的list前进一步。Iteration即可。

### 利用merge two lists
用[21_merge_two_sorted_lists](./21_merge_two_sorted_lists.md)里的函数，反复调用。

### Optimization using priority queue
多个乱序，可以通过priority queue每次拿到当前最大或最小的。

可以对brute force方式由priority queue进行排序，或者对每次做比较的方式，把每次的比较通过插入priority queue的方式进行。

### Optimization using **Divide And Conquer**
对利用merge two lists的方法，对原lists，两两配对，进行merge。分而治之。

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
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

class Solution {
 public:
  // Brute Force
  ListNode* mergeKLists2(vector<ListNode*>& lists) {
    std::vector<int> nums { };
    for (auto &i : lists) {
      while (i != NULL) {
        nums.push_back(i->val);
        i = i->next;
      }
    }
    std::sort(nums.begin(), nums.end());

    ListNode *head { NULL }, *tail { NULL };
    for (int i = 0; i < nums.size(); ++i) {
      if (head == NULL && tail == NULL) {
        head = new ListNode(nums[i]);
        tail = head;
      } else {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
      }
    }
    return head;
  }

  // Compare each one
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int index_of_smallest = 0;
    bool is_empty = true;
    int smallest { };
    ListNode *head { NULL }, *tail { NULL };

    do {
      is_empty = true;
      smallest = std::numeric_limits<decltype(smallest)>::max();

      for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] == NULL)
          continue;
        is_empty = false;
        if (lists[i]->val < smallest) {
          smallest = lists[i]->val;
          index_of_smallest = i;
        }
      }

      if (smallest != std::numeric_limits<decltype(smallest)>::max()) {
        if (head == NULL && tail == NULL) {
          head = new ListNode(smallest);
          tail = head;
        } else {
          tail->next = new ListNode(smallest);
          tail = tail->next;
        }
        lists[index_of_smallest] = lists[index_of_smallest]->next;
      }
    } while (!is_empty);

    return head;
  }
};
```
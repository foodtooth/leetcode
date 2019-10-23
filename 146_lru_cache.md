https://leetcode.com/problems/lru-cache/

## Idea
涉及 **O(1)** 的时间要求，考虑用**map**（由[**Hash table**](https://en.wikipedia.org/wiki/Hash_table)实现）。

涉及**list like**数据结构的操作要求 **O(1)** 的，考虑[**Doubly linked list**](https://en.wikipedia.org/wiki/Doubly_linked_list)。

## Code

```cpp
#include <unordered_map>
#include <list>
#include <utility>

class LRUCache {
  int capacity_ { };
  int key_ { };
  int value_ { };

 public:
  LRUCache() = default;
  LRUCache(decltype(capacity_) capacity)
      : capacity_ { capacity } {

  }

  int get(decltype(key_) key) {
    if (tracker_.count(key) != 0) {
      value_ = tracker_.at(key)->second;
      kvs_.splice(kvs_.begin(), kvs_, tracker_.at(key));
    } else {
      value_ = -1;
    }
    return value_;
  }

  void put(decltype(key_) key, decltype(value_) value) {
    if (tracker_.count(key) != 0) {
      // Update existing k-v in tracker_
      tracker_.at(key)->second = value;
      // Move used item to front
      kvs_.splice(kvs_.begin(), kvs_, tracker_.at(key));
    } else {
      if (kvs_.size() == capacity_) {
        tracker_.erase(kvs_.back().first);
        kvs_.pop_back();
      }
      kvs_.emplace_front(key, value);
      tracker_.emplace(key, kvs_.begin());
    }
  }

 private:
  std::list<std::pair<decltype(key_), decltype(value_)>> kvs_;
  std::unordered_map<decltype(key_), decltype(kvs_)::iterator> tracker_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
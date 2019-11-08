---
title: 208. Implement Trie (Prefix Tree)
tags: leetcode
---

https://leetcode.com/problems/implement-trie-prefix-tree/

## Idea

## Code
```cpp
class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() : root_{NULL} {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    if (root_ == nullptr) {
      root_ = new Node();
    }
    auto n = root_;
    for (auto c : word) {
      if (n->children[c] == nullptr) {
        n->children[c] = new Node();
      }
      n = n->children[c];
    }
    n->end_of_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto n = root_;
    if (n == NULL) return false;
    for (auto c : word) {
      if (n->children.find(c) != n->children.end()) {
        n = n->children[c];
      } else {
        return false;
      }
    }
    return n->end_of_word;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto n = root_;
    if (n == NULL) return false;
    for (auto c : prefix) {
      if (n->children.find(c) != n->children.end()) {
        n = n->children[c];
      } else {
        return false;
      }
    }
    return true;
  }

  struct Node {
    bool end_of_word;
    std::unordered_map<char, Node *> children{};
  };

  Node *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
---
title: 211. Design Add and Search Words Data Structure
tags: leetcode
---

https://leetcode.com/problems/design-add-and-search-words-data-structure/

## Idea
Trie and Dfs.


## Code

```cpp=
class WordDictionary {
  struct Node {
    bool is_end{};
    std::array<Node*, 26> children{nullptr};
  };
  class Trie {
   public:
    Trie() = default;
    Trie(const std::vector<std::string>& v) {
      root_ = new Node();
      AddWords(v);
    }
    Node* GetRoot() { return root_; }
    void AddWords(const std::vector<std::string>& v) {
      for (auto const& s : v) {
        AddWord(s);
      }
    }
    void AddWord(const std::string& s) {
      auto node = root_;
      for (auto const c : s) {
        auto index = c - 'a';
        if (node->children[index] == nullptr) {
          node->children[index] = new Node();
        }
        node = node->children[index];
      }
      node->is_end = true;
    }

   private:
    Node* root_ = new Node();
  };

 public:
  /** Initialize your data structure here. */
  WordDictionary() {}

  void addWord(string word) { t_.AddWord(word); }

  bool search(string word) {
    auto node = t_.GetRoot();
    return Dfs(word, node);
  }

 private:
  bool Dfs(const std::string& word, Node* node) {
    for (int i{}; i < word.length(); ++i) {
      auto c = word[i];
      if (c == '.') {
        bool r{};
        for (int j{}; j < node->children.size(); ++j) {
          if (node->children[j] != nullptr)
            r = r || Dfs(word.substr(i + 1), node->children[j]);
        }
        return r;
      } else if (node->children[c - 'a'] != nullptr) {
        node = node->children[c - 'a'];
      } else {
        return false;
      }
    }
    if (node->is_end)
      return true;
    else
      return false;
  }
  Trie t_{};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
---
title: 676. Implement Magic Dictionary
tags: leetcode
---

https://leetcode.com/problems/implement-magic-dictionary/

## Idea

## Code

```cpp=
class MagicDictionary {
  struct Node {
    bool is_end{};
    std::array<Node*, 26> children{nullptr};
  };
  class Trie {
   public:
    Trie() = default;
    explicit Trie(const std::vector<std::string>& v) { AddWords(v); }
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
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) { t_.AddWords(dictionary); }

  bool search(string searchWord) {
    auto node = t_.GetRoot();
    auto word_len = searchWord.length();
    for (int i{}; i < word_len; ++i) {
      if (Dfs(0, i, searchWord, node)) return true;
    }
    return false;
  }

 private:
  bool Dfs(int base, int index, const std::string& word, Node* node) {
    auto word_len = word.length();
    for (int i{base}; i < word_len; ++i) {
      if (i == index) {
        for (int j{}; j < node->children.size(); ++j) {
          if (node->children[j] != nullptr && (word[index] - 'a') != j) {
            if (Dfs(index + 1, index, word, node->children[j])) return true;
          }
        }
        return false;
      } else {
        if (node->children[word[i] - 'a'] != nullptr) {
          node = node->children[word[i] - 'a'];
        } else {
          return false;
        }
      }
    }
    if (node->is_end) return true;
    return false;
  }
  Trie t_{};
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
```
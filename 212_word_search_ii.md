---
title: 212. Word Search II
tags: leetcode
---

https://leetcode.com/problems/word-search-ii/

## Idea
Use `Trie` and DFS searching.

## Code

```cpp=
class Solution {
  struct Node {
    bool is_end{};
    std::vector<Node*> children{};
    Node() : is_end{false}, children(26, nullptr) {}
  };
  class Trie {
   public:
    Trie(const std::vector<std::string>& v) {
      root_ = new Node();
      AddWords(v);
    }
    Node* GetRoot() { return root_; }

   private:
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

    Node* root_{nullptr};
  };

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie t(words);
    auto row_size = board.size();
    auto column_size = board[0].size();
    for (int i{}; i < row_size; ++i) {
      for (int j{}; j < column_size; ++j) {
        std::string word{};
        Dfs(t.GetRoot(), word, i, j, board);
      }
    }
    std::vector<std::string> result{};
    for (auto const& word : words_) result.push_back(word);
    return result;
  }

 private:
  void Dfs(Node* node, std::string& word, int m, int n,
           std::vector<std::vector<char>>& board) {
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() ||
        board[m][n] == ' ')
      return;
    char c = board[m][n];
    int i = c - 'a';
    if (node->children[i] != nullptr)
      word += c;
    else
      return;
    node = node->children[i];
    if (node->is_end) words_.insert(word);
    board[m][n] = ' ';
    Dfs(node, word, m - 1, n, board);
    Dfs(node, word, m, n - 1, board);
    Dfs(node, word, m + 1, n, board);
    Dfs(node, word, m, n + 1, board);
    board[m][n] = c;
  }
  std::set<std::string> words_{};
};
```
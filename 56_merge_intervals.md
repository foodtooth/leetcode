https://leetcode.com/problems/merge-intervals/

## Idea

## Code
### Straight forward one
This one had a poor performance. `erase` operation invokes `move` which will cost a lot.
```cpp
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [](decltype(intervals.front()) &a, decltype(intervals.front()) &b) {
          return a.front() < b.front();
        });
    for (auto it = intervals.begin(); it + 1 < intervals.end();) {
      if (it->back() >= (it + 1)->back()) {
        intervals.erase(it + 1);
      } else if (it->back() >= (it + 1)->front()) {
        it->back() = (it + 1)->back();
        intervals.erase(it + 1);
      } else {
        ++it;
      }
    }
    return intervals;
  }
};
```

### Return-new-vector version
```cpp
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [](decltype(intervals.front()) &a, decltype(intervals.front()) &b) {
          return a.front() < b.front();
        });
    std::vector<std::vector<int>> result;
    for (auto &i : intervals) {
      if (result.empty()) {
        result.push_back(i);
        continue;
      }

      if (result.back().back() >= i.back())
        continue;
      else if (result.back().back() >= i.front())
        result.back().back() = i.back();
      else
        result.push_back(i);
    }
    return result;
  }
};
```
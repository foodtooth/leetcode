---
title: 1396. Design Underground System
tags: leetcode
---

https://leetcode.com/problems/design-underground-system/

## Idea

Hash tables provide $O(n)$ access.

## Code

```cpp=
class UndergroundSystem {
 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    check_ins_[id] = std::make_pair(stationName, t);
  }

  void checkOut(int id, string stationName, int t) {
    auto [s, t_in] = check_ins_[id];
    auto key = s + "->" + stationName;
    auto [total, count] = stats_[key];
    stats_[key] = std::make_pair(total + (t - t_in), count + 1);
  }

  double getAverageTime(string startStation, string endStation) {
    auto [total, count] = stats_[startStation + "->" + endStation];
    return total * 1. / count;
  }

 private:
  std::unordered_map<int, std::pair<std::string, int>> check_ins_{};
  std::unordered_map<std::string, std::pair<int, int>> stats_{};
};
```
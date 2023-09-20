#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using std::cout, std::endl;
class Solution {
private:
  struct ev {
    enum ev_type { start, end };
    ev_type ty;
    int loc;
    int hgt;
  };

public:
  std::vector<std::vector<int>>
  getSkyline(std::vector<std::vector<int>> &buildings) {
    size_t n = buildings.size();
    std::multiset<int> alive{0};

    std::vector<ev> evs;
    evs.reserve(2 * n);
    for (const auto &b : buildings) {
      evs.push_back({ev::start, b[0], b[2]});
      evs.push_back({ev::end, b[1], b[2]});
    }
    std::sort(evs.begin(), evs.end(), [&](const ev &a, const ev &b) {
      if (a.loc != b.loc)
        return a.loc < b.loc;
      if (a.ty == ev::start && b.ty == ev::start)
        return a.hgt > b.hgt;
      if (a.ty == ev::end && b.ty == ev::end)
        return a.hgt < b.hgt;
      return a.ty == ev::start;
    });

    std::vector<std::vector<int>> critical;
    critical.reserve(2 * n);
    for (const auto [ty, loc, hgt] : evs) {
      if (ty == ev::start) {
        if (hgt > *alive.rbegin()) {
          critical.push_back({loc, hgt});
        }
        alive.insert(hgt);
      } else {
        auto it = alive.find(hgt);
        if (it == alive.end()) {
          std::cerr << "something broke" << endl;
          return {};
        }
        alive.erase(it);
        auto max = *alive.rbegin();
        if (hgt > max) {
          critical.push_back({loc, max});
        }
      }
    }
    return critical;
  }
};

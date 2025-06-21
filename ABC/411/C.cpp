// 不正解解答
// TLE

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

void displayG(vector<P> G) {
  rep(i, 0, G.size()) {
    cout << "{ " << G.at(i).first << " " << G.at(i).second << " }";
    cout << endl;
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<bool> mass(N, false);

  vector<P> true_ranges;

  rep(i, 0, Q) {
    int A;
    cin >> A;

    if (mass[A - 1]) {
      mass[A - 1] = false;
      for (size_t i = 0; i < true_ranges.size(); ++i) {
        P &range = true_ranges[i];
        if (range.first == range.second && range.first == A - 1) {
          true_ranges.erase(true_ranges.begin() + i);
        }
        if (A - 1 == range.first) {
          ++range.first;
        }
        if (A - 1 == range.second) {
          --range.second;
        }
        if (A - 1 > range.first && A - 1 < range.second) {
          true_ranges.erase(true_ranges.begin() + i);
          true_ranges.push_back({range.first, A - 2});
          true_ranges.push_back({A, range.second});
        }
      }
    } else {
      mass[A - 1] = true;
      bool is_change = false;
      for (P &range : true_ranges) {
        if (A - 1 == range.first - 1) {
          range.first = A - 1;
          is_change = true;
          break;
        }
        if (A - 1 == range.second + 1) {
          range.second = A - 1;
          is_change = true;
          break;
        }
      }
      if (!is_change) {
        true_ranges.push_back({A - 1, A - 1});
      } else {
        for (size_t i = 0; i < true_ranges.size() - 1; ++i) {
          P &range = true_ranges[i];
          P &range2 = true_ranges[i + 1];
          if (range.second + 1 == range2.first) {
            true_ranges.erase(true_ranges.begin() + i);
            true_ranges.erase(true_ranges.begin() + i + 1);
            true_ranges.push_back({range.first, range2.second});
            break;
          }
          if (range.first == range2.second + 1) {
            true_ranges.erase(true_ranges.begin() + i);
            true_ranges.erase(true_ranges.begin() + i + 1);
            true_ranges.push_back({range2.first, range.second});
            break;
          }
        }
      }
    }

    displayG(true_ranges);

    cout << true_ranges.size() << endl;
  }
}
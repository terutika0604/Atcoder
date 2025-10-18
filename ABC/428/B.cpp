#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  map<string, int> result;

  rep(i, 0, N - K + 1) {
    string part = S.substr(i, K);

    if (result.find(part) != result.end()) {
      ++result[part];
    } else {
      result[part] = 1;
    }
  }

  int max = -99999;
  for (auto [k, v] : result) {
    if (v > max) {
      max = v;
    }
  }

  cout << max << endl;

  for (auto [k, v] : result) {
    if (v == max) {
      cout << k << " ";
    }
  }

  cout << endl;
}
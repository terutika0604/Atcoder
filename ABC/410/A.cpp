#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, K;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) { cin >> A.at(i); }
  cin >> K;

  int cnt = 0;
  rep(i, 0, N) {
    if (A.at(i) >= K) {
      ++cnt;
    };
  }

  cout << cnt << endl;
}
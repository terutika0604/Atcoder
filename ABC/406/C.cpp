#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<ll> A(N);
  rep(i, 0, N) { A.at(i) = i + 1; }

  int virtual_shift = 0;

  rep(i, 0, Q) {
    int type;
    cin >> type;

    int p, x;
    ll k;

    int next_index;

    switch (type) {
    case 1:
      cin >> p >> x;
      next_index = p - 1 + virtual_shift;
      if (next_index >= N) {
        next_index = next_index - N;
      }
      A.at(next_index) = x;

      break;
    case 2:
      cin >> p;
      next_index = p - 1 + virtual_shift;
      if (next_index >= N) {
        next_index = next_index - N;
      }

      cout << A.at(next_index) << endl;

      break;
    case 3:
      cin >> k;
      virtual_shift = (k + virtual_shift) % N;

      break;
    }
  }
}
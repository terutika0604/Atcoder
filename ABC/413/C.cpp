#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int Q;
  cin >> Q;

  vector<pair<ll, ll>> A;

  ll index = 0;

  rep(i, 0, Q) {
    int type;
    cin >> type;

    ll c, x, k, result = 0;

    switch (type) {
    case 1:
      cin >> c >> x;
      A.push_back({c, x});
      break;

    case 2:
      cin >> k;
      result = 0;
      rep(j, index, A.size()) {
        if (k > A[j].first) {
          result += A[j].second * A[j].first;
          k -= A[j].first;
          ++index;
        } else {
          result += A[j].second * k;
          A[j].first -= k;
          break;
        }
      }
      cout << result << endl;
      break;
    }
  }
}
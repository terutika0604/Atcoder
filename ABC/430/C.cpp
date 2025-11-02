// 累積和としゃくとり？解けず、、
// TLE

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int l = 0;
  set<P> ranges;
  vector<int> a(N + 1, 0), b(N + 1, 0);

  rep(i, 1, N + 1) {
    char c;
    cin >> c;

    if (c == 'a') {
      a[i] = a[i - 1] + 1;
      b[i] = b[i - 1];
    } else {
      a[i] = a[i - 1];
      b[i] = b[i - 1] + 1;
    }
  }

  rep(r, 0, N) {
    int nowA = a[r + 1] - a[l];
    int nowB = b[r + 1] - b[l];

    if (nowA < A) {
      continue;
    }
    if (nowB >= B) {
      r = l;
      ++l;
      continue;
    }

    ranges.insert({l, r});
  }

  cout << ranges.size() << endl;
}
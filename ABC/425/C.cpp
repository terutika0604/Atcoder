// TLE 31行目でc回ループがO(N)かかる
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);

  rep(i, 0, N) { cin >> A[i]; }

  // 累積和を前計算
  vector<int> s(N + 1, 0);
  for (int i = 0; i < N; ++i)
    s[i + 1] = s[i] + A[i];

  int accessIndex = 0;

  rep(i, 0, Q) {
    int type, c, l, r;
    cin >> type;

    if (type == 1) {
      cin >> c;
      rep(j, 0, c) {
        s.push_back(s.back() + A[accessIndex % N]);
        ++accessIndex;
      }
    }
    if (type == 2) {
      cin >> l >> r;
      cout << s[accessIndex + r] - s[accessIndex + l - 1] << endl;
    }
  }
}
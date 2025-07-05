// 不正解解答

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int T;
  cin >> T;

  rep(i, 0, T) {
    int N;
    cin >> N;
    vector<ll> test_list(N);
    rep(j, 0, N) { cin >> test_list[j]; }
    sort(test_list.begin(), test_list.end(), greater<ll>());

    ll r;
    bool isTouhi = true;
    rep(j, 0, N - 1) {
      if (j == 0) {
        r = test_list[j] / test_list[j + 1];
      } else {
        // 絶対値にソートして降順に並べ変える ⇒ 途中一部のみ正負が反転する配列を誤判定する[81 54 -36
        // 24 -16]
        if (r != test_list[j] / test_list[j + 1]) {
          isTouhi = false;
          break;
        }
      }
    }
    if (isTouhi) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
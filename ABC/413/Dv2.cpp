// https://atcoder.jp/contests/abc413/editorial/13404 参考
// 等比数列判定

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

  // 1つの入力ファイルにおけるNの総和は2×10^5以下であるため、T×Nは2×10^5に保たれており、T回のループの中でN回ループを回すことができる
  rep(i, 0, T) {
    int N;
    cin >> N;
    vector<ll> test_list(N);
    rep(j, 0, N) { cin >> test_list[j]; }

    // すべて同じ値なら、Yes
    // r = 1の場合
    if (count(test_list.begin(), test_list.end(), test_list[0]) == N) { // O(n)
      cout << "Yes" << endl;
      continue;
    }

    // 先頭とその -1 倍しかなく、それぞれ ceil(N/2) 個と floor(N/2) 個なら、Yes
    // r = -1の場合
    ll first = test_list[0];
    ll positive_count = count(test_list.begin(), test_list.end(), first);  // O(n)
    ll negative_count = count(test_list.begin(), test_list.end(), -first); // O(n)
    // [x, -x, x, -x, x]などに対応
    bool balanced_counts = (min(positive_count, negative_count) == N / 2);
    if (positive_count + negative_count == N && balanced_counts) {
      cout << "Yes" << endl;
      continue;
    }

    // 絶対値の降順にソートする
    sort(test_list.begin(), test_list.end(),
         [](ll a, ll b) { return abs(a) > abs(b); }); // O(nlogn)

    bool isTouhi = true;
    // iの2個先までアクセスするのでN-2まで
    rep(j, 0, N - 2) { // O(n)
      if (test_list[j] * test_list[j + 2] != test_list[j + 1] * test_list[j + 1]) {
        isTouhi = false;
        break;
      }
    }

    if (isTouhi) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
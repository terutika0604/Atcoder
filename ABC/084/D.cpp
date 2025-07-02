// エラトステネスのふるい
// 累積和

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

  int max = 100010;

  // エラトステネスのふるいを作っておく
  vector<bool> is_prime(max, true);

  is_prime[0] = false;
  is_prime[1] = false;

  rep(i, 2, max) {
    if (!is_prime[i])
      continue;

    for (int j = 2; i * j < max; ++j) {
      is_prime[i * j] = false;
    }
  }

  // 2017に似た数の累積和
  vector<int> is_lile_2017(max + 1, 0);
  for (int i = 0; i < max; ++i) {
    if (i % 2 == 1 && is_prime[i] && is_prime[(i + 1) / 2]) {
      is_lile_2017[i + 1] = is_lile_2017[i] + 1;
    } else {
      is_lile_2017[i + 1] = is_lile_2017[i];
    }
  }

  rep(i, 0, Q) {
    int l, r;
    cin >> l >> r;

    cout << is_lile_2017[r + 1] - is_lile_2017[l] << endl;
  }
}
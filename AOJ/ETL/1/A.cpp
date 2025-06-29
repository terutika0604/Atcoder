// 高速な素数判定法

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

// bool is_prime(ll N) {
//   for (ll i = 2; i < sqrt(N); ++i) {
//     if (N % i == 0)
//       return false;
//   }
//   return true;
// }

int main() {
  ll n;
  cin >> n;

  cout << n << ":";

  // パターン1　nを素数で割れるだけ割って更新していく
  // iはnまでインクリメントされ、素数チェックO(sqrt(n))が毎回呼び出されるため、遅い
  // ll i = 2;
  // while (n > 1) {
  //   if (is_prime(i)) {
  //     while (n % i == 0) {
  //       n /= i;
  //       cout << " " << i;
  //     }
  //   }
  //   ++i;
  // }

  // パターン2　nをiで割れるだけ割って更新していく=iはnまでいく
  // 素数でないものでもn % i == 0を試すため、遅い
  // ll i = 2;
  // while (n > 1) {
  //   while (n % i == 0) {
  //     n /= i;
  //     cout << " " << i;
  //   }
  //   ++i;
  // }

  // パターン3　iはsqrt(n)までしかいかない＆nは割られてlog的に小さくなる
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      cout << " " << i;
    }
  }

  if (n != 1) {
    cout << " " << n;
  }

  cout << endl;
}
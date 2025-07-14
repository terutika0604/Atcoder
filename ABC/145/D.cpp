#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

const ll MAX = 1000100;
ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  // 0の逆元は存在しないためあえて初期化せず
  fac[1] = fac[0] = 1;
  finv[1] = 1;
  inv[1] = 1;
  rep(i, 2, MAX) {
    // n!の累積積的な計算
    fac[i] = fac[i - 1] * i % MOD;
    // 拡張ユークリッドから導かれるMODにおけるiの逆元の計算
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    // (n^-1)!もn!のように累積積で計算できる
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;

  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int X, Y;
  cin >> X >> Y;

  COMinit();

  double x = (-X + 2 * Y) / 3.0, y = (2 * X - Y) / 3.0;

  if (x == 0 || y == 0) {
    cout << 1 << endl;
  } else if (floor(x) == x && floor(y) == y) {
    // x+yCxを求める
    int int_x = static_cast<int>(round(x));
    int int_y = static_cast<int>(round(y));
    cout << COM(int_x + int_y, int_x) << endl;
  } else {
    cout << 0 << endl;
  }
}
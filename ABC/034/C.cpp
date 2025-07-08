// 二項係数のあまり問題
// 逆元

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

const int MAX = 1010000;
ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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
  int W, H;
  cin >> W >> H;

  COMinit();

  cout << COM(W + H - 2, W - 1) << endl;
}
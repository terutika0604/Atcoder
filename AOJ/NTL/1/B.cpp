// べき乗を高速に計算するアルゴリズム
// a^bをmで割った余りをO(logb)で計算する

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  ll m;
  ll n;

  cin >> m >> n;

  ll mod = 1000000007;
  ll result = 1;

  while (n > 0) {
    // nの1ビット目が1だったら掛け算実装
    if (n & 1) {
      // 計算の途中過程で積極的にあまりをとってよい
      result = result * m % mod;
    }
    // mの更新　1乗➝2乗➝4乗
    m = m * m % mod;
    // 1ビット右シフト
    n >>= 1;
  }

  cout << result << endl;
}
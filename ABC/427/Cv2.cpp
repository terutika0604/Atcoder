// https://atcoder.jp/contests/abc427/editorial/14194
// bit全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edges(M);
  for (auto &&[u, v] : edges) {
    cin >> u >> v;
    --u; // 0-indexed にしておく
    --v;
  }
  int ans = M;
  // 2^N 通りの塗り方を全部探索する
  // 例）N=3、000,001,010,011,100,101,110,111の全探索
  for (int bit = 0; bit < 1 << N; ++bit) {
    int delete_count = 0;
    for (const auto &[u, v] : edges) {          // それぞれの辺を見て
      if ((1 & (bit >> u)) == (1 & (bit >> v))) // 結んでいる頂点が同じ色で塗られていたら
        ++delete_count;                         // カウントを増やす
    }
    ans = min(ans, delete_count); // 全部の塗り方にわたる最小値が答え
  }
  cout << ans << endl;
}
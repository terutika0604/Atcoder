// ワーシャルフロイド法（全頂点対最短経路）

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int V, E;
  cin >> V >> E;

  // k番目までのノードを経由地として使い、iからjまで移動したときの最小距離
  vector<vector<ll>> dp(V, vector<ll>(V, INF));

  // 自分自身への経路は0
  rep(i, 0, V) { dp[i][i] = 0; }

  rep(i, 0, E) {
    int s, t, d;
    cin >> s >> t >> d;

    // sとtは経由地なしで繋がっている＝最短距離であることが保証されている
    // ※有効グラフかつ、多重辺がない場合に限る
    dp[s][t] = d;
  }

  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
      }
    }
  }

  // ワーシャル–フロイド法は負の閉路に弱い
  //  負の経路のの検出
  rep(i, 0, V) {
    if (dp[i][i] < 0) {
      // 頂点 i を含む負の閉路が存在する
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  rep(i, 0, V) {
    rep(j, 0, V) {
      // ==での比較では数がでかすぎてうまくいかない
      // ÷2した値より大きくても無限大と考える
      if (dp[i][j] > INF / 2) {
        cout << "INF";
      } else {
        cout << dp[i][j];
      }
      if (j != V - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}
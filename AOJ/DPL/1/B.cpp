// ナップザックdp

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int N, W;
  cin >> N >> W;

  // dp[n+1][w] n番目までの荷物の中からwを超えない範囲で荷物を選んだ時の価値の最大値
  int dp[N + 1][W + 1];    // vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  int weight[N], value[N]; // vector<int> value(N), weight(N);

  rep(n, 0, N) {
    cin >> value[n];
    cin >> weight[n];
  }
  rep(w, 0, W + 1) { dp[0][w] = 0; }

  // n=0の初期値はあらかじめ決めておいて、ループの中でn+1を決める処理なのでn回ループでよい
  // wはw+1回のループが必要！！！！
  rep(n, 0, N) rep(w, 0, W + 1) {
    if (w >= weight[n]) {
      // n=1,w=2の時
      // dp[n][w - weight[n]] = 0, value[n] = 5,  dp[n][w] = 4
      // よってdp[n + 1][w] = 5
      dp[n + 1][w] = max(dp[n][w - weight[n]] + value[n], dp[n][w]);
    } else {
      dp[n + 1][w] = dp[n][w];
    }
  }

  // rep(n, 0, N + 1) {
  //   rep(w, 0, W + 1) { cout << dp[n][w] << " "; }
  //   cout << endl;
  // }
  cout << dp[N][W] << endl;
}
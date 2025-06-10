// dp 最小個数部分和問題

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> coins(M);
  rep(i, 0, M) { cin >> coins.at(i); }

  // dp[m][n]=m種類のコインを使って金額nを作るために必要な最小個数
  vector<vector<int>> dp(M + 1, vector<int>(N + 1, INF));
  // 0種類のコインを使って金額nを作ることができないため、無限大（INF）に設定
  // 0種類のコインをつかって金額0を作る最小個数のみ0!!!
  dp.at(0).at(0) = 0;

  rep(m, 0, M) rep(n, 0, N + 1) {
    if (n >= coins[m]) {
      // コインを選ぶ場合
      dp[m + 1][n] = min(dp[m + 1][n - coins[m]] + 1, min(dp[m][n - coins[m]] + 1, dp[m][n]));
    } else {
      // コインを選ばない場合
      dp[m + 1][n] = dp[m][n];
    }
  }

  cout << dp[M][N] << endl;
}
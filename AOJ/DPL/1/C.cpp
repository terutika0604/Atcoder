// dp ナップザック問題

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
  vector<int> value(N), weight(N);

  rep(i, 0, N) { cin >> value[i] >> weight[i]; }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  rep(n, 0, N) {
    rep(w, 0, W + 1) {
      if (w >= weight[n]) {
        dp[n + 1][w] = max(dp[n + 1][w - weight[n]] + value[n],
                           max(dp[n][w - weight[n]] + value[n], dp[n][w]));
      } else {
        dp[n + 1][w] = dp[n][w];
      }
    }
  }
  cout << dp[N][W] << endl;
}
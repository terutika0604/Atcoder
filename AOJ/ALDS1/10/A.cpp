// ナップザックDP

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;

  int dp[n];

  // 1 1 2 3 5 8 ....

  dp[0] = 1;
  dp[1] = 1;

  rep(i, 1, n) { dp[i + 1] = dp[i] + dp[i - 1]; }

  cout << dp[n] << endl;
}
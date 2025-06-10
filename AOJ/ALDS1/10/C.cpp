// dp 最長共通部分列(LCS)

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int q;
  cin >> q;

  rep(i, 0, q) {
    string X, Y;
    cin >> X >> Y;

    // dp[xi][yi] = Xのxi字目までとYのyi字目までのLCSの長さ
    // Xが5文字 X.size() = 5, Yが4文字 Y.size() = 4
    // 配列をX.size()で初期化すると {0, 0, 0, 0, 0} indexは4まで作られる
    // X.size() + 1で初期化するとindexは5(=X.size())まで作られる
    // 答えはdp[X.size()][Y.size()] (=dp[5][4])
    vector<vector<int>> dp(X.size() + 1, vector<int>(Y.size() + 1));
    // Xの0文字目までとYの0文字目までのLCSの長さは0で初期化
    // とはいえ未初期化の値は元々0
    dp[0][0] = 0;

    // XとかYとかにはindex0からアクセスしたい
    // それらを使って、dp[index+1]を格納していく（dpは＋１して更新する）
    rep(xi, 0, X.size()) rep(yi, 0, Y.size()) {
      if (X.at(xi) == Y.at(yi)) {
        // 〇〇〇の３文字目と△△の２文字目が一致するときのLCSの長さは以下となる
        // 〇〇,△のLCSの長さ+1
        dp[xi + 1][yi + 1] = max(dp[xi][yi] + 1, max(dp[xi + 1][yi], dp[xi][yi + 1]));
      } else {
        // 〇〇〇の３文字目と△△の２文字目が一致しないときのLCSの長さは以下２つにおいて変化しない
        // 〇〇,△△の時に〇を考慮する
        // 〇〇〇,△の時に△を考慮する
        dp[xi + 1][yi + 1] = max(dp[xi + 1][yi], dp[xi][yi + 1]);
      }
    }
    cout << dp[X.size()][Y.size()] << endl;
  }
}
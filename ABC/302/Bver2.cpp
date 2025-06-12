// GPT 効率的

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> S(H);
  rep(i, 0, H) { cin >> S.at(i); }

  int diff_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int diff_y[] = {0, -1, -1, -1, 0, 1, 1, 1};

  vector<P> result;
  string target = "snuke"; // ターゲットの文字列を生成

  rep(i, 0, H) rep(j, 0, W) {
    rep(k, 0, 8) {
      bool match = true;
      vector<P> temp;
      rep(t, 0, 5) {
        int ni = i + diff_y[k] * t;
        int nj = j + diff_x[k] * t;
        if (ni < 0 || nj < 0 || ni >= H || nj >= W || S[ni][nj] != target[t]) {
          match = false;
          break;
        }
        // targetのt番目と一致するかどうか見ていって、一致するならtmpについか
        temp.emplace_back(ni, nj);
      }
      // 一度もmatchが更新されない＝文字列一致
      if (match) {
        result = temp;
        break;
      }
    }
  }
}
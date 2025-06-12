// 効率悪い、、

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
  vector<P> result;

  int diff_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int diff_y[] = {0, -1, -1, -1, 0, 1, 1, 1};

  rep(i, 0, H) rep(j, 0, W) {
    if (S.at(i).at(j) == 's') {
      // 8方向にsがあるか
      rep(k, 0, 8) {
        int nj = j + diff_x[k];
        int ni = i + diff_y[k];
        // 場外判定
        if (nj < 0 || ni < 0 || nj >= W || ni >= H) {
          continue;
        }

        if (S.at(ni).at(nj) == 'n') {
          int n2j = nj + diff_x[k];
          int n2i = ni + diff_y[k];
          // 場外判定
          if (n2j < 0 || n2i < 0 || n2j >= W || n2i >= H) {
            continue;
          }

          if (S.at(n2i).at(n2j) == 'u') {
            int n3j = n2j + diff_x[k];
            int n3i = n2i + diff_y[k];
            // 場外判定
            if (n3j < 0 || n3i < 0 || n3j >= W || n3i >= H) {
              continue;
            }

            if (S.at(n3i).at(n3j) == 'k') {
              int n4j = n3j + diff_x[k];
              int n4i = n3i + diff_y[k];
              // 場外判定
              if (n4j < 0 || n4i < 0 || n4j >= W || n4i >= H) {
                continue;
              }

              if (S.at(n4i).at(n4j) == 'e') {
                result.push_back({i, j});
                result.push_back({ni, nj});
                result.push_back({n2i, n2j});
                result.push_back({n3i, n3j});
                result.push_back({n4i, n4j});
              }
            }
          }
        }
      }
    }
  }

  rep(i, 0, 5) { cout << result.at(i).first + 1 << " " << result.at(i).second + 1 << endl; }
}
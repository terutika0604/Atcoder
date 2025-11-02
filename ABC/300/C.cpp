#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

void search(int ni, int nj, int &n, vector<vector<bool>> &seen, vector<vector<char>> &C) {
  if (C[ni][nj] == '#') {
    ++n;
    seen[ni][nj] = true;
    search(ni + 1, nj + 1, n, seen, C);
  }
  return;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> C(H + 2, vector<char>(W + 2, '.'));
  vector<vector<bool>> seen(H + 2, vector<bool>(W + 2, false));
  vector<int> result(min(H, W), 0);

  rep(i, 1, H + 1) rep(j, 1, W + 1) { cin >> C[i][j]; }

  rep(i, 0, H + 2) rep(j, 0, W + 2) {
    if (seen[i][j])
      continue;

    int n = 0;
    seen[i][j] = true;

    if (C[i][j] == '#') {
      search(i + 1, j + 1, n, seen, C);

      if (n != 0) {
        ++result[n / 2 - 1];
      }
    }
  }

  rep(i, 0, min(H, W)) {
    cout << result[i];
    if (i != min(H, W) - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
}

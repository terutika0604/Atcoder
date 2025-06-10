#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int H, W;

bool check_match(vector<vector<char>> mapA, vector<vector<char>> mapB) {
  rep(i, 0, H) rep(j, 0, W) {
    if (mapA.at(i).at(j) != mapB.at(i).at(j))
      return false;
  }
  return true;
}

void displayG(vector<vector<char>> G) {
  rep(i, 0, G.size()) {
    rep(j, 0, G.at(i).size()) { cout << G.at(i).at(j) << " "; }
    cout << endl;
  }
}

int main() {
  cin >> H >> W;
  vector<vector<char>> mapA(H, vector<char>(W)), mapB(H, vector<char>(W));

  rep(i, 0, H) rep(j, 0, W) { cin >> mapA.at(i).at(j); }
  rep(i, 0, H) rep(j, 0, W) { cin >> mapB.at(i).at(j); }

  rep(i, 0, H) {
    // 縦回転
    if (i != 0) {
      rotate(mapA.begin(), mapA.begin() + 1, mapA.end());
    }

    rep(j, 0, W) {
      if (j != 0) {
        // 横回転
        rep(k, 0, H) { rotate(mapA.at(k).begin(), mapA.at(k).begin() + 1, mapA.at(k).end()); }
      }

      if (check_match(mapA, mapB)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
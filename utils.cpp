#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// キュー(座標)の中身をチェックする関数
void distplayQ(queue<P> q) {
  if (q.empty())
    cout << "q end" << endl;
  while (!q.empty()) {
    cout << "[ ";
    cout << " " << q.front().first + 1;
    cout << " " << q.front().second + 1 << " ";
    cout << " ]" << endl;
    q.pop();
  }
}

// グラフの中身をチェックする関数
void displayG(Graph G) {
  rep(i, 0, G.size()) {
    rep(j, 0, G.at(i).size()) { cout << G.at(i).at(j) << " "; }
    cout << endl;
  }
}
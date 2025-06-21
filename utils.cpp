#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

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

// 配列の中身をチェックする関数
void displayV(auto V) {
  cout << "V = [ ";
  rep(i, 0, V.size()) { cout << V.at(i) << " "; }
  cout << "]" << endl;
}

// 二次元配列の中身をチェックする関数
void displayVV(auto VV) {
  cout << "VV = [ " << endl;
  rep(i, 0, VV.size()) {
    rep(j, 0, VV.at(i).size()) { cout << VV.at(i).at(j) << " "; }
    cout << endl;
  }
  cout << " ]" << endl;
}

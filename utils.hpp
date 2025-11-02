#pragma once
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// -------------------------
// キュー(座標)の中身をチェックする関数
// -------------------------
inline void dispQ(queue<P> q) {
  if (q.empty())
    cout << "q end" << endl;
  while (!q.empty()) {
    cout << "[ " << q.front().first + 1 << " " << q.front().second + 1 << " ]" << endl;
    q.pop();
  }
}

// -------------------------
// 配列の中身をチェックする関数（テンプレート）
// -------------------------
template <typename T> void dispV(T V) {
  cout << "V = [ ";
  for (auto x : V)
    cout << x << " ";
  cout << "]" << endl;
}

// -------------------------
// 二次元配列の中身をチェックする関数（テンプレート）
// -------------------------
template <typename T> void dispVV(T VV) {
  cout << "VV = [ " << endl;
  for (int i = 0; i < VV.size(); i++) {
    for (int j = 0; j < VV[i].size(); j++)
      cout << VV[i][j] << " ";
    cout << endl;
  }
  cout << " ]" << endl;
}

// -------------------------
// Mapの中身をチェックする関数（テンプレート）
// -------------------------
template <typename T> void dispM(T m) {
  for (auto &[k, v] : m)
    cout << "(" << k << ":" << v << ") ";
  cout << endl;
}

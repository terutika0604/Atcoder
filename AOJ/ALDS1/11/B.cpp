// 深さ優先探索

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
#define Graph vector<vector<int>>


vector<bool> seen;
vector<int> d; //行きがけ
vector<int> v; //帰りがけ

void dfs(Graph &G, int i, int &ptr) {
  seen.at(i) = true;
  d.at(i) = ptr++;
  
  // iから行ける各頂点 next_i について
  for (auto next_i: G.at(i)) {
    if (seen.at(next_i)) continue;
    dfs(G, next_i, ptr);
  }
  
  v.at(i) = ptr++;
}

int main(){
  int n;
  cin >> n;

  // 連結配列とその確認コード
  Graph G(n);
  rep(i, 0, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, 0, k) {
      int v;
      cin >> v;
      G.at(u).push_back(v - 1);
    }
  }

  // rep(i, 0, n) {
  //   cout << "G[" << i << "] = {";
  //   rep(j, 0, G.at(i).size()) {
  //     cout << G.at(i).at(j) << ",";
  //   }
  //   cout << "}" << endl;
  // }

  seen.assign(n, false);
  d.resize(n);
  v.resize(n);
  int ptr = 0;

  rep(i, 0, n) {
    if (!seen.at(i)) dfs(G, i, ptr);
  }

  rep(i, 0, n) {

    cout << i + 1 << " ";
    cout << d.at(i) + 1 << " " << v.at(i) + 1 << endl;
  }
}
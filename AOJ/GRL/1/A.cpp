// ダイクストラ法（単一始点最短経路問題）

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int V, E, r;
  cin >> V >> E >> r;

  // ある点から進める次点とそこへの移動距離をセットで格納
  vector<vector<pair<ll, int>>> Edges(V);
  rep(i, 0, E) {
    int s, t, d;
    cin >> s >> t >> d;
    Edges.at(s).push_back({d, t});
  }

  // 始点の情報とそこへの距離(距離でソートするから最初は距離)
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
  // dist.at(i) 始点からiへの移動したときの距離の最小値
  vector<ll> dist_list(V, INF);

  dist_list[r] = 0;
  pque.push({0, r});

  while (!pque.empty()) {
    // p.first:始点までの総距離、p.second:始点の情報
    auto [total_dist, sorce] = pque.top();
    pque.pop();

    // 始点までの総距離が、すでに求められている総距離より大きい場合は先に進む必要なし
    if (dist_list.at(sorce) < total_dist)
      continue;

    for (auto [dist, to] : Edges.at(sorce)) {
      // 次点の情報とそこへの距離(始点までの最短距離+始点から時点までの移動距離)を追加
      ll new_dist = dist_list.at(sorce) + dist;
      if (new_dist < dist_list.at(to)) {
        // 最短距離の更新
        dist_list.at(to) = new_dist;
        pque.push({new_dist, to});
      }
    }
  }

  rep(i, 0, V) {
    ll output = dist_list.at(i);
    if (output == INF) {
      cout << "INF" << endl;
    } else {
      cout << output << endl;
    }
  }
}
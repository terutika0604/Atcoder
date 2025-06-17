// ダイクストラ法（単一始点最短経路問題）

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

void dijkstra(int sorce, int target, const vector<vector<P>> &G) {
  PQ pq;
  // 始点から各点への最小の移動コスト
  vector<ll> dist(110, INF);

  dist[sorce] = 0;
  pq.push({0, sorce});

  while (!pq.empty()) {
    auto [cost, prev_v] = pq.top();
    pq.pop();

    if (dist[prev_v] < cost) {
      continue;
    }

    for (auto [next_cost, next_v] : G[prev_v]) {
      // cout << "next_cost is " << next_cost << endl;
      // cout << "next_v is " << next_v << endl;

      ll new_dist = dist[prev_v] + next_cost;
      if (new_dist < dist[next_v]) {
        dist[next_v] = new_dist;
        // cout << "push " << new_dist << ", " << next_v << endl;
        pq.push({new_dist, next_v});
      }
    }
  }

  if (dist[target] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[target] << endl;
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<P>> G(110);

  rep(i, 0, k) {
    int type, sorce, target, cost;
    cin >> type;

    switch (type) {
    case 0:
      cin >> sorce >> target;
      --sorce;
      --target;
      dijkstra(sorce, target, G);
      break;

    case 1:
      cin >> sorce >> target >> cost;
      --sorce;
      --target;
      G[sorce].push_back({cost, target});
      G[target].push_back({cost, sorce});
      break;
    }
  }
}
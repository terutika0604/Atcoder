// 2部グラフの最小削除数
// 幅優先探索➝開始頂点や探索順に依存するたWA

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

void displayVV(auto VV) {
  cout << "VV = [ " << endl;
  rep(i, 0, VV.size()) {
    rep(j, 0, VV.at(i).size()) { cout << VV.at(i).at(j) << " "; }
    cout << endl;
  }
  cout << " ]" << endl;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);

  int ans = 9999;

  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    G.at(u - 1).push_back(v - 1);
    G.at(v - 1).push_back(u - 1);
  }

  rep(i, 0, N) {
    vector<int> dist(N, -1);
    queue<int> que;
    set<pair<int, int>> removed;

    dist.at(i) = 0;
    que.push(i);
    int anskamo = 0;

    while (!que.empty()) {
      int v = que.front();
      que.pop();

      for (int next_v : G.at(v)) {
        if (removed.count({min(v, next_v), max(v, next_v)}))
          continue;

        if (dist.at(next_v) != -1) {
          if (dist[v] == dist[next_v]) {
            removed.insert({min(v, next_v), max(v, next_v)});
            ++anskamo;
          }
          continue;
        }

        dist.at(next_v) = 1 - dist.at(v);
        que.push(next_v);
      }
    }

    ans = min(anskamo, ans);
  }

  cout << ans << endl;
}
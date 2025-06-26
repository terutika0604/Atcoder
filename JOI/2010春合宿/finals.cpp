// 最小全域木問題
// クラスカル法
// 経路圧縮
// union by rank

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

struct UnionFind {
  vector<int> parent, rank;

  // 自身が根であることは-1で表す
  UnionFind(int V) : parent(V, -1), rank(V, 0) {}

  // 経路圧縮について
  // Union-Find において重要なのは「根が同じであれば同じ集合」ということだけ
  // 中間の経路はどれだけ変更しても、「集合の分け方」自体には影響しない
  // union by rankよりも時間短縮効果が大きい
  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      return parent[x] = root(parent[x]); // 経路圧縮
    }
  }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return false;

    // union by rank
    if (rank[rx] < rank[ry])
      swap(rx, ry);
    parent[ry] = rx; // rankが小さいほう（ry）をrxにつける

    if (rank[rx] == rank[ry])
      ++rank[rx]; // rankが同じならrx側のrankを調整する
    return true;
  }

  bool same(int x, int y) { return root(x) == root(y); }
};

struct edge {
  int s;
  int t;
  int cost;
};

bool compare_edge(const edge &a, const edge &b) { return a.cost < b.cost; }

struct Kruskal {
  int sum = 0;

  // 木をK分割するため、costが大きい順にedgeを切るための配列
  vector<int> max_cost;

  Kruskal(vector<edge> edges, int V) {
    UnionFind unionFind(V);

    sort(edges.begin(), edges.end(), compare_edge);

    for (auto edge : edges) {
      if (!unionFind.same(edge.s, edge.t)) {
        unionFind.unite(edge.s, edge.t);
        max_cost.push_back(edge.cost);
        sum += edge.cost;
      }
    }
  }
};

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<edge> edges;

  rep(i, 0, M) {
    int s, t, cost;
    cin >> s >> t >> cost;

    edges.push_back(edge{s - 1, t - 1, cost});
  }

  Kruskal kruskal(edges, N);
  sort(kruskal.max_cost.begin(), kruskal.max_cost.end(), greater<int>());

  int update_sum = kruskal.sum;

  rep(i, 0, K - 1) { update_sum -= kruskal.max_cost[i]; }
  cout << update_sum << endl;
}
// UnionFind
// 最小全域木問題
// クラスカル法

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

struct UnionFind {
  // parent[i] = iの親番号
  vector<int> parent;

  UnionFind(int V) : parent(V) {
    for (int i = 0; i < V; ++i) {
      parent[i] = i;
    }
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (parent[x] == x) {
      return x;
    } else {
      return root(parent[x]);
    }
  }

  void unite(int x, int y) { // xとyの木を併合
    if (root(x) == root(y))
      return;
    parent[root(y)] = root(x);
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }
};

// Edgeの構造体
// つないでいるノードとそのcostを管理
struct edge {
  int s;
  int t;
  ll cost;
};
// Edgeをソートするための比較関数
bool compareByCost(const edge &a, const edge &b) { return a.cost < b.cost; }

// クラスカル法実装のための構造体
struct Kruskal {
  ll sum = 0;
  Kruskal(vector<edge> edges, int V) {
    UnionFind unionfind(V);

    // edgeを小さい順に並び変える 計算量：O(ElogE)
    sort(edges.begin(), edges.end(), compareByCost);

    for (auto edge : edges) {
      if (!unionfind.same(edge.s, edge.t)) {
        unionfind.unite(edge.s, edge.t);
        sum += edge.cost;
      }
    }
  }
};

int main() {
  int V, E;

  cin >> V >> E;

  vector<edge> Edges(E);

  rep(i, 0, E) {
    int s, t, w;
    cin >> s >> t >> w;

    Edges[i] = edge{s, t, w};
  }

  Kruskal krs(Edges, V);
  cout << krs.sum << endl;
}
// UnionFind

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

struct UnionFind {
  vector<int> parent, rank;

  UnionFind(int V) : parent(V, -1), rank(V, 0) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      return parent[x] = root(parent[x]);
    }
  }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return false;

    if (rank[rx] < rank[ry])
      swap(rx, ry);
    parent[ry] = rx;
    if (rank[rx] == rank[ry])
      ++rank[rx];
    return true;
  }

  bool same(int x, int y) { return root(x) == root(y); }
};

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> X(N), Y(N);
  rep(i, 0, N) cin >> X[i] >> Y[i];

  UnionFind unionfind(N);

  rep(i, 0, N) rep(j, 0, N) {
    int dist = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
    if (dist <= D * D) {
      unionfind.unite(i, j);
    }
  }

  rep(i, 0, N) {
    if (unionfind.same(0, i)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
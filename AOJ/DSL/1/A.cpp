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
  int n, q;
  cin >> n >> q;

  UnionFind unionFind(n);

  rep(i, 0, q) {
    int com, x, y;
    cin >> com >> x >> y;

    switch (com) {
    case 0:
      unionFind.unite(x, y);
      break;

    case 1:
      if (unionFind.same(x, y)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
      break;

    default:
      break;
    }
  }
}
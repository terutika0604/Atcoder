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
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  int result = 0;
  rep(e, 0, M) {
    UnionFind unionfind(N);

    rep(i, 0, M) {
      // 辺 e を除外したUnionFindを生成
      if (i == e)
        continue;
      unionfind.unite(A[i], B[i]);
    }

    // 連結成分の個数を求める　＝　Rootの数を求める
    int num = 0;
    for (int v = 0; v < N; ++v) {
      if (unionfind.root(v) == v)
        ++num;
    }
    // 連結成分数が 1 より大きいと非連結
    // 連結　= すべてのノードの親が単一
    if (num > 1)
      ++result;
  }

  cout << result << endl;
}
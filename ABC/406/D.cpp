#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, M;
  cin >> N >> M;

  Graph G(N);
  vector<ll> W(M);

  rep(i, 0, M) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    G.at(a - 1).push_back(b - 1);
    W.at(i) = w;
  }
}
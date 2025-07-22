#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(M, vector<int>(N, 0));
  vector<set<int>> friends(N);

  rep(i, 0, M) rep(j, 0, N) {
    cin >> G[i][j];
    --G[i][j];
  }

  rep(i, 0, M) rep(j, 0, N - 1) {
    int a = G[i][j];
    int b = G[i][j + 1];
    friends[a].insert(b);
    friends[b].insert(a);
  }

  int res = 0;
  rep(i, 0, N) rep(j, 0, N) {
    if (i == j)
      continue;
    if (friends[i].insert(j).second) {
      friends[j].insert(i);
      ++res;
    }
  }

  cout << res << endl;
}
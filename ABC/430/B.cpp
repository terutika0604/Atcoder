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

  if (N == M) {
    cout << 1 << endl;
    return 0;
  }

  vector<vector<char>> S(N, vector<char>(N));

  rep(i, 0, N) rep(j, 0, N) { cin >> S[i][j]; }

  int all = N - M + 1;
  set<string> pattern;

  rep(x, 0, all) rep(y, 0, all) {
    string bit;
    bit.reserve(M * M);
    rep(i, 0, M) rep(j, 0, M) {
      if (S[x + i][y + j] == '#')
        bit.push_back('1');
      else
        bit.push_back('0');
    }
    pattern.insert(bit);
  }

  cout << pattern.size() << endl;
}
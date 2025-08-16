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

  string S, T;
  cin >> S >> T;

  // いもす
  vector<int> table(N + 1, 0);

  rep(i, 0, M) {
    int L, R;
    cin >> L >> R;

    table.at(L - 1)++;
    table.at(R)--;
  }

  rep(i, 1, N + 1) { table.at(i) += table.at(i - 1); }

  rep(i, 0, N) {
    if (table[i] % 2 != 0) {
      S[i] = T[i];
    }
  }

  cout << S << endl;
}
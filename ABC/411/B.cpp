#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;
  vector<int> D(N - 1);

  rep(i, 0, N - 1) { cin >> D[i]; }

  int i = 0;
  while (i <= D.size()) {
    int dist = 0;
    rep(j, i, N - 1) {
      dist += D[j];
      if (j == N - 2) {
        cout << dist << endl;
      } else {
        cout << dist << " ";
      }
    }
    ++i;
  }
}
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
  map<int, int> M;

  rep(i, 0, N) {
    int Ti;
    cin >> Ti;
    M[Ti] = i + 1;
  }

  int i = 0;
  for (auto &p : M) {
    if (i == 3)
      return 0;
    cout << p.second << endl;
    i++;
  }
}
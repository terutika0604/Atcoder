#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  rep(i, 0, N) {
    int ans = A + B;
    int c;
    cin >> c;

    if (c == ans) {
      cout << i + 1 << endl;
      break;
    }
  }
}
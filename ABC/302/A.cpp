
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  ll A, B;
  cin >> A >> B;

  ll cnt = A / B;

  if (A % B == 0) {
    cout << cnt << endl;
  } else {
    cout << cnt + 1 << endl;
  }
}
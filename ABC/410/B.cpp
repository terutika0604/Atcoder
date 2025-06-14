#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> Box(N);
  vector<int> B_out(Q);

  rep(i, 0, Q) {
    int x;
    cin >> x;

    if (x == 0) {
      auto min = min_element(begin(Box), end(Box));
      int index = distance(Box.begin(), min);

      ++Box.at(index);
      B_out.at(i) = index + 1;
    } else {
      ++Box.at(x - 1);
      B_out.at(i) = x;
    }
  }

  rep(i, 0, Q) { cout << B_out.at(i) << " "; }
  cout << endl;
}
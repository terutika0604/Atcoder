#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>


int main() {
  int N;
  cin >> N;
  vector<int> T(N + 1);
  vector<int> X(N + 1);
  vector<int> Y(N + 1);

  T.at(0) = X.at(0) = Y.at(0) = 0;

  rep(i, 0, N) {
    cin >> T.at(i + 1) >> X.at(i + 1) >> Y.at(i + 1);
  }

  bool can = true;

  rep(i, 0, N) {
    // tの差分
    int dt = T.at(i + 1) - T.at(i);
    // 移動距離の差分
    int dist = abs(X.at(i + 1) - X.at(i)) + abs(Y.at(i + 1) - Y.at(i));
    // tより多く移動することはできない
    // dtとdistの偶奇は常に一致する！
    if (dist > dt || dist % 2 != dt % 2) {
      can = false;
      break;
    };
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
}

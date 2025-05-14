#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long;
// #include <algorithm>

int main() {
  int N, Y;
  cin >> N >> Y;

  rep(i, 0, N + 1) rep(j, 0, N + 1) {
    int sum = 10000 * i + 5000 * j + 1000 * (N - i - j);
    if((N - i - j) < 0) {
      continue;
    } 
    if (sum == Y) {
      cout << i << " " << j << " " << (N - i - j) << " " << endl;
      return 0;
    }
  }

  cout << -1 << " " << -1 << " " << -1 << " " << endl;
  // cout << -1 -1 -1 << endl;
}

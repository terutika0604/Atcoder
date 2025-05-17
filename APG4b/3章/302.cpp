#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>


int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> P(N);

  rep(i, 0, N) {
    int a,b;
    cin >> a >> b;
    P.at(i) = make_pair(b, a);
  }

  sort(P.begin(), P.end());

  rep(i, 0, N) {
    cout << P.at(i).second << " " << P.at(i).first << endl;
  }
}

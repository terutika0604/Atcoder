#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
#define Graph vector<vector<int>>

int main() {

  int N, S;
  cin >> N >> S;

  vector<int> T(N);

  rep(i, 0, N) {
    cin >> T.at(i);
  }

  int last_m = 0;

  rep(i, 0, N) {
    int tmp = last_m;
    last_m = T.at(i);

    if (last_m - tmp > S + 0.5) {
      cout << "No" << endl;
      return 0;
    };

  }

  cout << "Yes" << endl;

  
}
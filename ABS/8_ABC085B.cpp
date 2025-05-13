#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long;
#include <algorithm>

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, 0, N) cin >> D.at(i);

  sort(D.begin(), D.end(), greater<int>());

  int max = 0;
  int prev_d = 101;

  rep(i, 0, N) {
    if (D.at(i) < prev_d) {
      max++;
      prev_d = D.at(i);
    }
  }
  
  cout << max << endl;
}

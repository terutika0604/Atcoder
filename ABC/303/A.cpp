#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N;
  cin >> N;

  string S, T;
  cin >> S;
  cin >> T;

  bool match = true;
  rep(i, 0, N) {
    if (S.at(i) == T.at(i)) {
      continue;
    }
    if ((S.at(i) == '1' && T.at(i) == 'l') || (S.at(i) == 'l' && T.at(i) == '1')) {
      continue;
    }
    if ((S.at(i) == '0' && T.at(i) == 'o') || (S.at(i) == 'o' && T.at(i) == '0')) {
      continue;
    }
    match = false;
    break;
  }

  if (match) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
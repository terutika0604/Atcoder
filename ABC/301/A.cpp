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
  string S;
  cin >> N >> S;

  int twin = 0;
  int awin = 0;

  for (char c : S) {
    if (c == 'T') {
      ++twin;
    }
    if (c == 'A') {
      ++awin;
    }
  }

  if (twin == awin) {
    if (S[S.size() - 1] == 'A') {
      cout << "T" << endl;
    } else {
      cout << "A" << endl;
    }
    return 0;
  }

  if (twin > awin) {
    cout << "T" << endl;
  } else {
    cout << "A" << endl;
  }
}
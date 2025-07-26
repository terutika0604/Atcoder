#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  string S;
  cin >> S;
  bool can_put_maru = true;

  rep(i, 0, S.size()) {
    if (S[i] == '#') {
      cout << '#';
      can_put_maru = true;
      continue;
    }
    if (S[i] == '.') {
      if (can_put_maru) {
        cout << 'o';
        can_put_maru = false;
      } else
        cout << '.';
    }
  }

  cout << endl;
}
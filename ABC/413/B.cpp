#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;

  vector<string> S(N);

  rep(i, 0, N) { cin >> S[i]; }

  set<string> set_str;

  rep(i, 0, N) rep(j, 0, N) {
    if (i == j)
      continue;
    string new_str = S[i] + S[j];
    set_str.insert(new_str);
  }

  cout << set_str.size() << endl;
}
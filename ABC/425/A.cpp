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

  int result = 0;
  rep(i, 0, N) {
    int addResult = (i + 1) * (i + 1) * (i + 1);
    if ((i + 1) % 2 != 0) {
      addResult = -1 * addResult;
    }
    result += addResult;
  }

  cout << result << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int Q;
  cin >> Q;

  priority_queue<int, vector<int>, greater<int>> pq;

  rep(i, 0, Q) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;

      pq.push(x);

    } else {
      cout << pq.top() << endl;
      pq.pop();
    }
  }
}
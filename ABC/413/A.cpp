#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;

  int sum = 0;
  rep(i, 0, N) {
    int a;
    cin >> a;
    sum += a;
  }

  if (sum > M) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

void checkHealPoint(P now, set<P> &XY, int &H, int K) {
  if (H < K && XY.count(now)) {
    XY.erase(now);
    H = K;
  }
}

int main() {
  int N, M, H, K;
  cin >> N >> M >> H >> K;
  vector<char> S(N);
  rep(i, 0, N) { cin >> S[i]; }
  set<P> XY;
  rep(i, 0, M) {
    int x, y;
    cin >> x >> y;
    XY.insert({x, y});
  }

  P now = {0, 0};
  rep(i, 0, N) {
    switch (S[i]) {
    case 'R':
      ++now.first;
      --H;
      if (H < 0) {
        cout << "No" << endl;
        return 0;
      }

      checkHealPoint(now, XY, H, K);
      break;
    case 'L':
      --now.first;
      --H;
      if (H < 0) {
        cout << "No" << endl;
        return 0;
      }

      checkHealPoint(now, XY, H, K);
      break;
    case 'U':
      ++now.second;
      --H;
      if (H < 0) {
        cout << "No" << endl;
        return 0;
      }
      checkHealPoint(now, XY, H, K);
      break;
    case 'D':
      --now.second;
      --H;
      if (H < 0) {
        cout << "No" << endl;
        return 0;
      }
      checkHealPoint(now, XY, H, K);
      break;
    default:
      break;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
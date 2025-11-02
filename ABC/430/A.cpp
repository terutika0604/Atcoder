#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if (C >= A) {
    if (D < B) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
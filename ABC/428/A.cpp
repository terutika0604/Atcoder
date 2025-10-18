#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int S, A, B, X;
  cin >> S >> A >> B >> X;

  int result = 0;
  int tmp = A;

  rep(i, 0, X) {

    if (tmp > 0) {
      result += S;
      --tmp;
    } else {
      i += (B - 1);
      tmp = A;
    }
  }

  cout << result << endl;
}
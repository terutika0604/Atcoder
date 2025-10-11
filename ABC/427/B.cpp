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
  int a = 1;

  rep(i, 0, N) {
    while (a >= 10) {
      result += (a % 10);
      a = a / 10;
    }

    result += a;
    a = result;
  }

  cout << result << endl;
}
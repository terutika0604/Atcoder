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

  rep(i, 0, 21) {
    int a = i * 5;
    int b = (i + 1) * 5;
    if (a <= N && N <= b) {
      if ((N - a) < (b - N)) {
        cout << a << endl;
        break;
      } else {
        cout << b << endl;
        break;
      }
    }
  }
}
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

  int res = N;

  int d8 = N / 100000000;
  N = N - d8 * 100000000;
  int d7 = N / 10000000;
  N = N - d7 * 10000000;
  int d6 = N / 1000000;
  N = N - d6 * 1000000;
  int d5 = N / 100000;
  N = N - d5 * 100000;
  int d4 = N / 10000;
  N = N - d4 * 10000;
  int d3 = N / 1000;
  N = N - d3 * 1000;
  int d2 = N / 100;
  N = N - d2 * 100;
  int d1 = N / 10;
  N = N - d1 * 10;

  if (res < 1000) {         // ^3
  } else if (res < 10000) { // ^4
    // res = N - N % 10で十分、、、
    res = d3 * 1000 + d2 * 100 + d1 * 10;
  } else if (res < 100000) { // ^5
    res = d4 * 10000 + d3 * 1000 + d2 * 100;
  } else if (res < 1000000) { // ^6
    res = d5 * 100000 + d4 * 10000 + d3 * 1000;
  } else if (res < 10000000) { // ^7
    res = d6 * 1000000 + d5 * 100000 + d4 * 10000;
  } else if (res < 100000000) { // ^8
    res = d7 * 10000000 + d6 * 1000000 + d5 * 100000;
  } else if (res < 1000000000) { // ^9
    res = d8 * 100000000 + d7 * 10000000 + d6 * 1000000;
  }

  cout << res << endl;
}
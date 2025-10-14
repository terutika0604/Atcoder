#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int toInt(char c) {
  switch (c) {
  case 'A':
    return 0;
    break;

  case 'B':
    return 1;
    break;

  case 'C':
    return 2;
    break;

  case 'D':
    return 3;
    break;

  case 'E':
    return 4;
    break;

  case 'F':
    return 5;
    break;

  case 'G':
    return 6;
    break;

  default:
    break;
  }
}

int main() {
  char p, q;
  cin >> p >> q;
  int distance[7] = {0, 3, 4, 8, 9, 14, 23};

  int r = max(toInt(p), toInt(q));
  int l = min(toInt(p), toInt(q));

  cout << distance[r] - distance[l] << endl;
}
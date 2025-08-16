#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {

  string S;
  cin >> S;

  if (S == "red") {
    cout << "SSS" << endl;
  } else if (S == "blue") {
    cout << "FFF" << endl;
  } else if (S == "green") {
    cout << "MMM" << endl;
  } else {
    cout << "Unknown" << endl;
  }
}
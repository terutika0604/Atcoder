#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, L, R;
  string S;

  cin >> N >> L >> R;
  cin >> S;

  rep(i, L - 1, R) { 
    if(S[i] != 'o') {
      cout << "No" << endl; 
      return 0;
    }
  }

  cout << "Yes" << endl; 

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<string> S(N);

  int max = pow(N, K);
  vector<string> Fs(max);
  rep(i, 0, N) { cin >> S[i]; }

  // K桁のN進数で表す
  // N = 3 K = 2
  // 0 S[0]S[0] 1 S[0]S[1]
  // 3 S[1][0]
  // 8 S[2][2]
  rep(i, 0, max) { // 0 - i - 8
    int x = i;
    if (x == 0) {
      rep(j, 0, K) { Fs[i] += S[0]; }
      continue;
    }

    // N進数への変換
    vector<int> digits;
    while (x > 0) {
      digits.push_back(x % N);
      x = x / N;
    }
    // 残りのビットを0で埋める
    while (digits.size() != K) {
      digits.push_back(0);
    }

    rep(j, 0, K) { Fs[i] += S[digits[j]]; }
  }

  sort(Fs.begin(), Fs.end());
  cout << Fs[X - 1] << endl;
}
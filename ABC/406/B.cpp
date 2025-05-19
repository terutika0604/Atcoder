#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>

// N=1 K=18 A= [100000000000000000, 2]

int main() {
  size_t N, K;
  cin >> N >> K;

  vector<ll> A(N);

  rep(i, 0, N) {
    cin >> A.at(i);
  }
  
  ll result = 1;
  
  rep(i, 0, N) {

    // かけ算の結果がオーバーフローするかを事前に桁数でチェック
    int digits_current = to_string(result).size();
    int digits_next = to_string(A[i]).size();

    // result * A[i] の最大桁数をざっくり推定
    if (digits_current + digits_next - 1 >= K + 1) {
      result = 1; // K+1 桁以上になりそうならリセット
    } else {
      result *= A[i];
    }

    if (to_string(result).size() > K) {
      result = 1;
    }
  }

  cout << result << endl;
  
}

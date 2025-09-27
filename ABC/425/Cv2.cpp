// 工夫が必要な累積和
// 模範解答を参考にAIが作成
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<ll> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  // 配列を2倍にする
  vector<ll> B = A;
  B.insert(B.end(), A.begin(), A.end());

  // 後ろからの累積和（suffix sum）
  for (int i = 2 * N - 1; i > 0; --i) {
    B[i - 1] += B[i];
  }

  int shift = 0;
  while (Q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int c;
      cin >> c;
      shift = (shift + c) % N;
    } else {
      int l, r;
      cin >> l >> r;
      --l; // 0-index に直す
      cout << B[l + shift] - B[r + shift] << "\n";
    }
  }
}

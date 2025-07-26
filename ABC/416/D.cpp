#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int T;
  cin >> T;

  rep(t, 0, T) {
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N), B(N);

    rep(i, 0, N) { cin >> A[i]; }
    rep(i, 0, N) { cin >> B[i]; }

    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end());

    int index = 0, C = 0;
    rep(i, 0, N) {
      while (index < N && A[i] + B[index] < M) {
        ++index;
      }
      // 配列の外＝足してMを超える組み合わせが見つからなかった
      if (index >= N)
        break;
      ++C;
      // 次以降見ていくAは今の値より大きいので今マッチングしたBの値より大きい値は見る必要なし
      // = indexをインクリメントして次以降のマッチングを探す
      ++index;
    }

    ll sumA = accumulate(A.begin(), A.end(), 0LL);
    ll sumB = accumulate(B.begin(), B.end(), 0LL);

    cout << sumA + sumB - C * M << endl;
  }
}
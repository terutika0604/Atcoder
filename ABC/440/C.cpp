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

  while (T--) {
    int N, W;
    cin >> N >> W;
    vector<ll> C(N);
    rep(i, 0, N) { cin >> C[i]; }

    // 2W 周期で考える
    int period = 2 * W;

    // 2W 長の配列を作成
    vector<long long> arr(period, 0LL);

    rep(i, 0, N) { arr[i % period] += C[i]; }

    // 最初の W 個の和を求める
    long long current_sum = 0;
    for (int i = 0; i < W; ++i) {
      current_sum += arr[i];
    }

    long long ans = current_sum;

    // スライドして最小値更新
    for (int i = 1; i < period; ++i) {
      current_sum -= arr[(i - 1) % period];
      current_sum += arr[(i + W - 1) % period];
      ans = min(ans, current_sum);
    }

    cout << ans << "\n";
  }
  return 0;
}
// 累積和×2分探索（めぐる式）
// https://atcoder.jp/contests/abc430/editorial/14299
// https://www.youtube.com/live/W9jftsWrLQA

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int get_al(int l, int A, vector<int> &prefA) {
  int L = l, R = prefA.size();
  // 最後の実行ではLとRが隣になってる
  // L: 条件を満たさない領域
  // R: 条件を満たす領域
  while (R - L > 1) {
    int mid = (L + R) / 2;
    // aの個数 = prefA[r] - prefA[l]
    if (prefA[mid] - prefA[l] >= A) {
      R = mid;
    } else {
      L = mid;
    }
  }
  return R;
}

int get_bl(int l, int B, vector<int> &prefB) {
  int L = l, R = prefB.size();
  while (R - L > 1) {
    int mid = (L + R) / 2;
    if (prefB[mid] - prefB[l] < B) {
      L = mid;
    } else {
      R = mid;
    }
  }
  return L;
}

int main() {

  int N, A, B;
  cin >> N >> A >> B;

  ll result = 0;
  vector<int> prefA(N + 1, 0), prefB(N + 1, 0);

  rep(i, 0, N) {
    char c;
    cin >> c;

    prefA[i + 1] = prefA[i] + (c == 'a' ? 1 : 0);
    prefB[i + 1] = prefB[i] + (c == 'b' ? 1 : 0);
  }

  rep(l, 0, N) {
    // lを固定したときに条件を満たすrがいくつあるか数え上げる
    // 以下を累積和の中から二分探索で求める
    // [l,r) に含まれる a の個数がA個以上となる最小のr = al
    // [l,r) に含まれる b の個数がB個未満となる最大のr = bl

    int al = get_al(l, A, prefA);
    int bl = get_bl(l, B, prefB);

    // この時al, blは累積和配列のインデックスを指していることに注意
    result += max(0, bl - al + 1);
  }

  cout << result << endl;
}
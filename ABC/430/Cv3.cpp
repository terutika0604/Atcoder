// 累積和×2分探索
// 普通の2分探索（すべての値を網羅する）

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int get_al(int l, int A, vector<int> &prefA) {
  int N = prefA.size() - 1;
  // 一度もalの更新が行われなかったら返る値
  // = aが4つ以上にならないパターンは番兵を返す
  int al = N + 1;

  int L = l, R = N;
  // 最後の実行ではL=Rになってる
  while (L <= R) {
    int mid = (L + R) / 2;
    // aの個数 = prefA[r] - prefA[l]
    if (prefA[mid] - prefA[l] >= A) {
      al = mid;
      // midは確認済みなので1個ずらして更新する
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return al;
}

int get_bl(int l, int B, vector<int> &prefB) {
  int N = prefB.size() - 1;
  int bl = l;

  int L = l, R = N;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (prefB[mid] - prefB[l] < B) {
      bl = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  return bl;
}

int main() {

  int N, A, B;
  cin >> N >> A >> B;

  ll result = 0;
  vector<int> prefA(N + 1, 0), prefB(N + 1, 0);

  rep(i, 1, N + 1) {
    char c;
    cin >> c;

    if (c == 'a') {
      prefA[i] = prefA[i - 1] + 1;
      prefB[i] = prefB[i - 1];
    } else {
      prefA[i] = prefA[i - 1];
      prefB[i] = prefB[i - 1] + 1;
    }
  }

  rep(l, 0, N) {
    // lを固定したときに条件を満たすrがいくつあるか数え上げる
    // 以下を累積和の中から二分探索で求める
    // [l,r) に含まれる a の個数がA個以上となる最小のr = al
    // [l,r) に含まれる b の個数がB個未満となる最大のr = bl

    int al = get_al(l, A, prefA);
    int bl = get_bl(l, B, prefB);
    result += max(0, bl - al + 1);
  }

  cout << result << endl;
}
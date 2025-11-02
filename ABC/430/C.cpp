// しゃくとり法（尺取り法）
// 今回のようにｒが左側に戻らないケースなら使える
// https://atcoder.jp/contests/abc430/submissions/70633012
// https://www.youtube.com/live/W9jftsWrLQA

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;

  ll ans = 0;
  int ra = 0, count_a = 0;
  int rb = 0, count_b = 0;
  rep(l, N) {
    // A個のaを満たすためにraを進める
    // raはaがA個以上となる最小の右端を指す
    while (ra < N && count_a < A) {
      if (S[ra] == 'a')
        count_a++;
      ra++;
    }
    // aがA個以上とならなかった場合
    if (ra == N && count_a < A)
      ra++;

    // B個のbを満たすためにrbを進める
    // rbはbがB個以上となる最小の右端を指す
    while (rb < N && count_b < B) {
      if (S[rb] == 'b')
        count_b++;
      rb++;
    }
    // bがB個以上とならなかった場合
    if (rb == N && count_b < B)
      rb++;

    ans += max(0, rb - ra);

    // lが進む＝最初の一文字目を消す必要がある
    if (S[l] == 'a')
      count_a--;
    if (S[l] == 'b')
      count_b--;
  }

  cout << ans << endl;
  return 0;
}
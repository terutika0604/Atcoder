// https://atcoder.jp/contests/abc411/editorial/13351

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q, x, s = 0;
  cin >> n >> q;

  // s = 変数マスiとマス(i+1)の色が異なるようなiの個数を管理する変数
  //  s/2が区間になり、答えとなる
  // a = マスiとマス(i+1)の色が異なっているかを管理する配列
  // 1が異なる、0が等しい

  vector<int> a(n + 1);
  for (int i = 0; i < q; i++) {
    cin >> x;
    // Xを反転したとき、以下それぞれでマスiとマス(i+1)の色が等しい⇒異なる。異なる⇒等しい
    //  i = X − 1
    a[x - 1] = 1 - a[x - 1];        // aの更新
    s += (1 - a[x - 1]) - a[x - 1]; // sの更新
    // i = X
    a[x] = 1 - a[x];        // aの更新
    s += (1 - a[x]) - a[x]; // sの更新

    // sは+2,-2,+-0のどれかになる
    //  白白白➝白黒白　+2
    //  白黒白➝白白白　-2
    //  黒白黒黒➝黒黒黒黒　-2
    //  白白黒黒➝白黒黒黒　+-0(i=X-1で+1,i=Xで-1)
    //  白白黒黒➝白白白黒　+-0(i=X-1で-1,i=Xで+1)

    cout << (s / 2) << endl;
  }

  return 0;
}

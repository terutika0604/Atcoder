// やってることは自分のと一緒
// queueで管理しなくても全探索するんだったら配列のお隣チェックしていくだけでいいよねって話
// https://atcoder.jp/contests/abc302/editorial/6408

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  sort(s.begin(), s.end());
  do {
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++)
        if (s[i][j] != s[i + 1][j])
          cnt++;
      if (cnt != 1)
        ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(s.begin(), s.end()));
  cout << "No" << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>


int main() {
  string S;
  cin >> S;

  vector<string> divide = {"dream", "dreamer", "erase", "eraser"};

  // 最初からマッチングすると被るので後ろからマッチングする
  reverse(S.begin(), S.end());
  rep(i, 0, 4) {
    reverse(divide.at(i).begin(), divide.at(i).end());
  }

  // 確認
  // cout << S << endl;
  // rep(i, 0, 4) {
    // cout << divide.at(i) << endl;
  // }

  // マッチしない場合はreturnされるので無限ループはしない
  for (int i = 0; i < S.size();) {
    bool can = false;
    rep(j, 0, 4) {
      string d = divide.at(j);
      if (S.substr(i, d.size()) == d) {
        i += d.size(); // 切り出した分iを進める！
        can = true;
      }
    }
    if(!can) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  
}

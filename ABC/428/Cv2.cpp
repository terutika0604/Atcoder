// 参考
// https://atcoder.jp/contests/abc428/submissions/70229680

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;
void yesno(bool f) { f ? cout << "Yes" << endl : cout << "No" << endl; }

int main() {
  int Q;
  cin >> Q;

  vector<int> v = {0}; // 累積和の保持
  map<int, int> mp;    // カッコ列のバランスを管理する（累積和の最小値を簡単に取得する）

  rep(i, 0, Q) {
    int type;
    char c;

    cin >> type;

    if (type == 1) {
      cin >> c;

      int add = v.back() + (c == '(' ? 1 : -1);
      v.push_back(add);
      mp[add]++; // 累積和をキーにしてValueをインクリメント（Value＝累積和の出現回数を表すが使わない）

    } else {
      int ere = v.back();
      v.pop_back();
      mp[ere]--; // Valueをデクリメント
      if (mp[ere] == 0)
        mp.erase(ere); // 最小値取得に影響する可能性から消す ())からtype2が入ったときとか
    }
    // mapはキーで昇順ソートされる ので、mp.begin()->first = 現在の累積和の最小値
    yesno(v.back() == 0 && (*mp.begin()).first >= 0);
  }
}
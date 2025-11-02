// 2分探索　
// 通常の2分探索（めぐる式でない）= 指定された値を見つける

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;
// #include <algorithm>
// #include <iomanip>

int main() {
  int n, q;

  cin >> n;
  vector<int> S(n);
  rep(i, 0, n) cin >> S.at(i);

  cin >> q;
  vector<int> T(q);
  rep(i, 0, q) cin >> T.at(i);

  int counter = 0;

  rep(i, 0, q) {
    int search_num = T.at(i);

    int start_index = 0;
    int end_index = S.size() - 1;

    // 探索範囲が0になるまで
    while (end_index >= start_index) {
      int middle_index = (start_index + end_index) / 2; // Sの中央のインデックス

      if (S.at(middle_index) == search_num) {
        // 指定された値（それ以外では処理を行わない）
        counter++;
        break;
      } else if (S.at(middle_index) > search_num) {
        end_index = middle_index - 1;
      } else if (S.at(middle_index) < search_num) {
        start_index = middle_index + 1;
      }
    }
  }

  cout << counter << endl;

  return 0;
}
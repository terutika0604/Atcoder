#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, 0, N) { cin >> A.at(i); }

  // int insert_cnt = 0;
  // int i = 0;
  // int original_size = A.size();
  // while (true) {
  //   if (i == (original_size + insert_cnt - 1)) {
  //     break;
  //   }
  //   int ft = A.at(i);
  //   int next = A.at(i + 1);

  //   if (ft < next && next != ft + 1) {
  //     A.insert(A.begin() + i + 1, ft + 1);
  //     ++insert_cnt;
  //   } else if (ft > next && next != ft - 1) {
  //     A.insert(A.begin() + i + 1, ft - 1);
  //     ++insert_cnt;
  //   }
  //   ++i;
  // }

  // 上のコードのリファクタ
  // 各要素を一回ずつ見て、挿入するだけで十分
  for (size_t i = 1; i < A.size(); ++i) {
    int ft = A.at(i - 1);
    int next = A.at(i);

    if (ft + 1 < next) {
      A.insert(A.begin() + i, ft + 1);
    }
    if (ft - 1 > next) {
      A.insert(A.begin() + i, ft - 1);
    }
  }

  for (size_t i = 0; i < A.size(); ++i) {
    cout << A.at(i);
    if (i == A.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
// 　いもす法

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
#define Graph vector<vector<int>>

int main() {

  int N, M;
  cin >> N >> M;

  // ある壁を守っている砲台個数を格納する
  vector<int> wall_table(N + 1, 0);

  rep(i, 0, M) {
    int L, R;
    cin >> L >> R;
    // 内部的にはfor分を使っており、M×NでTLEする
    // transform(wall_table.begin() + L - 1, wall_table.begin() + R, wall_table.begin() + L - 1,
    //                [](int x) { return x + 1; });

    // 　いもす法による解答
    wall_table.at(L - 1)++;
    wall_table.at(R)--;
  }

  // 　いもす法による解答
  //  O(MN) ➝ O(M+N)
  rep(i, 1, N + 1) { wall_table.at(i) += wall_table.at(i - 1); }

  auto min_it = min_element(wall_table.begin(), wall_table.end() - 1);
  cout << *min_it << endl;
}
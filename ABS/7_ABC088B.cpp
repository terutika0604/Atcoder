#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long;

int max_index_in_arry(vector<int> A) {
  int max = 0;
  int max_index = 0;
  rep(i, 0, A.size()) {
      if (A.at(i) > max) {
        max = A.at(i);
        max_index = i;
      }
  }
  return max_index;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) cin >> A.at(i);

  int alice_sum = 0;
  int bob_sum = 0;

  rep(i, 0, N) {
    // Aの中で一番大きい数字をalice_sumに足してAから除く
    // Aの中で一番大きい数字をbob_sumに足してAから除く 繰り返し
    int max_index = max_index_in_arry(A);
    // （解説後）sortしてから取ればわざわざmax_index_in_arryを作る必要はなかった！
    if (i % 2 == 0) {
      alice_sum += A.at(max_index);
    } else {
      bob_sum += A.at(max_index);
    }
    A.erase(A.begin() + max_index);
  }
  
  cout << alice_sum - bob_sum << endl;
}

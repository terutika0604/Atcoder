#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A.at(i);
  }

  int div_counter = 0;

  while (true) {
    rep(i, 0, N) {
      if (A.at(i) % 2 != 0) {
        cout << div_counter << endl;
        return 0;
      }
      A.at(i) = A.at(i) / 2; // 割った数で再代入
    }
    div_counter++;
  }
  
  

}

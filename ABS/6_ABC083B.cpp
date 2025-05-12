#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int result_sum = 0;

  rep(i, 1, N + 1) {
    string s = to_string(i);
    if (s.size() == 1) {
      // 1桁の場合
      if (i >= A && i <= B) result_sum += i;
    } else {
      int sum = 0;
      for (char c : s) {
        int num = c - '0'; //ASCII値を用いた変換
        sum += num;
      }
      if (sum >= A && sum <= B) result_sum += i;
    }
  }
  
  cout << result_sum << endl;

}

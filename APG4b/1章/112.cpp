#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int cal = 1;

  for (size_t i = 0; i < S.size(); i++) {
    int num = 1;
    if (i % 2 == 0) continue;

    if (S.at(i) == '+') {
      cal += num;
    } else if (S.at(i) == '-') {
      cal -= num;
    } else {
      cout << "error" << endl;
    }
  }
  
  cout << cal << endl;

}

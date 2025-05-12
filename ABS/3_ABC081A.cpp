#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int one_counter = 0;
  for (char c : s) {
    if (c == '1') {
      one_counter++;
    }
  }

  cout << one_counter << endl;
}

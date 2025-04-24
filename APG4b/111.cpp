#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  for (int i = 0; i < N; i++) {
    string op;
    int x;
    cin >> op >> x;

    cout << i + 1 << ":";

    if (op == "+") {
      A += x;
    } else if (op == "-") {
      A -= x;
    } else if (op == "*") {
      A *= x;
    } else if (op == "/") {
      if (x == 0) {
        cout << "error" << endl;
        return 0;
      }
      A /= x;
    }

    cout << A << endl;

  }
}

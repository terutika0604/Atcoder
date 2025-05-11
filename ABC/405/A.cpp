#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, X;
  cin >> R >> X;

  if (X == 1) {
    if (R >= 1600 && R < 3000) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (R >= 1200 && R < 2400) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  
}

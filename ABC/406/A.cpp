#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  if (a > c) {
    cout << "Yes" << endl;
  } else if (a < c) {
    cout << "No" << endl;
  } else {
    if (b > d) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
}

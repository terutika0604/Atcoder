#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int counter = 0;

  rep(i500, 0, A + 1) rep(i100, 0, B + 1) rep(i50, 0, C + 1) {
    if (500 * i500 + 100 * i100 + 50 * i50 == X) {
      counter++;
    }
  }
  
  cout << counter << endl;

}

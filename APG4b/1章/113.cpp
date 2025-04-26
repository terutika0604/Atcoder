#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> vec(N);
  int sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }

  int ave = sum / N;

  for (int i = 0; i < N; i++) {
    int diff =  ave - vec.at(i);
    if (diff < 0) diff *= -1;
    cout << diff << endl;
  }
}

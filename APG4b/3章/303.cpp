#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>


int main() {
  int N;
  cin >> N;
  // vector<int> A(N);

  // rep(i, 0, N) {
  //   cin >> A.at(i);
  // }

  map<int, int> mapA;
  rep(i, 0, N) {
    int a_in = 0;
    cin >> a_in;
    if (mapA.count(a_in)) {
      mapA.at(a_in)++;
    } else {
      mapA[a_in] = 1;
    }
  }

  int max_count = 0;
  int max_num = 0;
  
  for (auto a : mapA) {
    int num = a.first;
    int count = a.second;
    if (count > max_count) {
      max_count = count;
      max_num = num;
    }
  }

  cout << max_num << " " << max_count << endl;
  
}

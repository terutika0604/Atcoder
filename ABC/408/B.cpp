#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
#define Graph vector<vector<int>>

int main() {

  int N;
  cin >> N;

  vector<int> set_int;

  rep(i, 0, N) {
    int A;
    cin >> A;

    if (i == 0) {
      set_int.push_back(A);
      continue;
    }

    bool is_duplication = false;
    rep(j, 0, set_int.size()){
      if(set_int.at(j) == A) {
        is_duplication = true;
        break;
      }
    }

    if (!is_duplication) {
      set_int.push_back(A);
    }
  }


  sort(set_int.begin(), set_int.end());

  cout << set_int.size() << endl;

  rep(i, 0, set_int.size()) {
    cout << set_int.at(i);
    if (i == set_int.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  
}
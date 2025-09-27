#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;

  int minusCount = 0;
  vector<int> A(N);
  vector<int> originalA(N);

  rep(i, 0, N) {
    int Ai;
    cin >> Ai;
    if (Ai == -1) {
      ++minusCount;
    }
    A.at(i) = Ai;
    originalA.at(i) = Ai;
  }

  set<int> lackOfNumList;

  sort(A.begin(), A.end());

  rep(i, 0, N) {
    bool toAdd = true;
    rep(j, minusCount, N) {
      if (i + 1 == A[j]) {
        toAdd = false;
        continue;
      }
    }
    if (toAdd) {
      lackOfNumList.insert(i + 1);
    }
  }

  if (minusCount != lackOfNumList.size()) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    auto it = lackOfNumList.begin();
    rep(i, 0, N) {
      if (originalA[i] == -1) {
        cout << *it;
        ++it;
      } else {
        cout << originalA[i];
      }
      if (i != N - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}
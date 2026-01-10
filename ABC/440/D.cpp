// 不正解回答　解きなおしたら消す
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> An(N);
  rep(i, 0, N) {
    int A;
    cin >> A;
    An[i] = A;
  }

  sort(An.begin(), An.end());

  rep(i, 0, Q) {
    int X, Y;
    cin >> X >> Y;

    int count = lower_bound(An.begin(), An.end(), X + Y) - lower_bound(An.begin(), An.end(), X);

    // cout << X + Y - 1 << endl;
    cout << lower_bound(An.begin(), An.end(), X + Y) - An.begin() << endl;
    cout << lower_bound(An.begin(), An.end(), X) - An.begin() << endl;
    cout << count << endl;
    cout << "//////" << endl;
  }
}
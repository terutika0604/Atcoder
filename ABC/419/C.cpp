#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;

  vector<ll> R(N);
  vector<ll> C(N);

  rep(i, 0, N) { cin >> R[i] >> C[i]; }

  auto [min_r_it, max_r_it] = minmax_element(R.begin(), R.end());
  auto [min_c_it, max_c_it] = minmax_element(C.begin(), C.end());

  ll abs_r = (*max_r_it + *min_r_it) / 2;
  ll abs_c = (*max_c_it + *min_c_it) / 2;

  ll max_r_g = 0;
  ll max_c_g = 0;

  rep(i, 0, N) {
    max_r_g = max(abs(R[i] - abs_r), max_r_g);
    max_c_g = max(abs(C[i] - abs_c), max_c_g);
  }

  cout << max(max_r_g, max_c_g) << endl;
}
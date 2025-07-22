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
  vector<string> name(N);
  vector<ll> old(N);

  rep(i, 0, N) { cin >> name[i] >> old[i]; }

  int min_index = min_element(old.begin(), old.end()) - old.begin();

  int i = min_index;
  do {
    cout << name[i] << endl;
    ++i;
    if (i >= name.size()) {
      i = 0;
    }
  } while (i != min_index);
}
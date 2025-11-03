// 順列全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

class Utils {
public:
  static void displayQ(queue<string> q) {
    if (q.empty())
      cout << "q end" << endl;
    while (!q.empty()) {
      cout << "[ " << q.front() << " ]" << endl;
      q.pop();
    }
  }

  static void displayQP(queue<P> q) {
    if (q.empty())
      cout << "q end" << endl;
    while (!q.empty()) {
      cout << "[ " << q.front().first + 1 << " " << q.front().second + 1 << " ]" << endl;
      q.pop();
    }
  }

  static void displayV(auto V) {
    cout << "V = [ ";
    rep(i, 0, V.size()) { cout << V.at(i) << " "; }
    cout << "]" << endl;
  }

  static void displayVV(auto VV) {
    cout << "VV = [ " << endl;
    rep(i, 0, VV.size()) {
      rep(j, 0, VV.at(i).size()) { cout << VV.at(i).at(j) << " "; }
      cout << endl;
    }
    cout << " ]" << endl;
  }

  static void displayMap(auto m) {
    for (const auto &[k, v] : m)
      cout << "(" << k << ":" << v << ") ";
    cout << endl;
  }
};

bool check(string S, string T) {
  bool ok = false;
  rep(i, 0, S.size()) {
    if (S[i] != T[i]) {
      if (ok) {
        return false;
      } else {
        ok = true;
      }
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);

  rep(i, 0, N) { cin >> S[i]; }
  sort(S.begin(), S.end());

  do {
    // create queue
    queue<string> sq;
    rep(i, 0, S.size()) { sq.push(S[i]); }
    string s = sq.front();
    sq.pop();
    bool ans = true;

    while (!sq.empty()) {
      bool ng = true;
      rep(i, 0, sq.size()) {
        string t = sq.front();
        sq.pop();
        if (check(s, t)) {
          s = t;
          ng = false;
          break;
        } else {
          sq.push(t);
        }
      }

      if (ng) {
        ans = false;
        break;
      }
    }

    if (ans) {
      cout << "Yes" << endl;
      return 0;
    }

  } while (next_permutation(S.begin(), S.end()));

  cout << "No" << endl;
}
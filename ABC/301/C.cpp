#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

class Utils {
public:
  static void displayQ(queue<P> q) {
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

int main() {
  string S, T;
  cin >> S >> T;

  map<char, int> Sm, Tm;
  set<char> allowed = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

  // @みたいなワイルとカードは別管理するとよい
  int Sat = 0;
  int Tat = 0;

  rep(i, 0, S.size()) {
    if (S[i] == '@')
      Sat++;
    else
      Sm[S[i]]++; // 無かったら自動で 0 → ++ される

    if (T[i] == '@')
      Tat++;
    else
      Tm[T[i]]++;
  }

  // 被り排除
  for (auto &[k, v] : Tm) {
    int m = min(v, Sm[k]); // 被りの数
    v -= m;
    Sm[k] -= m;
  }

  // Sの@と打ち消していく
  for (auto [k, v] : Tm) {
    if (v == 0)
      continue;

    if (allowed.count(k) && v <= Sat) {
      Sat -= v;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  // Tの@と打ち消していく
  for (auto [k, v] : Sm) {
    if (v == 0)
      continue;

    if (allowed.count(k) && v <= Tat) {
      Tat -= v;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  if (Tat == Sat) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
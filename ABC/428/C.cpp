// 良い括弧列である条件をうまく見つけ出せず
// 開きカッコの数＝＝閉じカッコの数
// &&
// 途中で閉じカッコが開きカッコより多くなっていない（左から読んでいって閉じカッコが多くなる瞬間がない）

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const ll INF = 1LL << 60;

char lastChar;
vector<bool> results;
vector<bool> oks;

void outputResult(int index, bool isAdd, map<char, int> &count, char c) {

  if (isAdd) {
    if (count['('] == count[')'] && results[index]) {
      cout << "Yes" << endl;
      oks.push_back(true);
    } else {
      cout << "No" << endl;
      oks.push_back(false);
    }
  } else {
    if (oks[index - 1]) {
      cout << "No" << endl;
    } else {
      if (index - 2 < 0) {
        cout << "Yes" << endl;
        oks.pop_back();
        return;
      }
      if (oks[index - 2]) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    results.pop_back();
  }
}

int main() {
  int Q;
  cin >> Q;

  map<char, int> count = {
      {'(', 0},
      {')', 0},
  };

  rep(i, 0, Q) {
    int type;
    char c;

    cin >> type;

    if (type == 1) {
      cin >> c;
      ++count[c];
      results.push_back(count['('] >= count[')']);
      outputResult(i, true, count, c); // ok
      lastChar = c;
    } else {
      --count[lastChar];
      results.pop_back();
      outputResult(i, false, count, c);
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  // A=勝者、B=敗者
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<string>> result(N, vector<string>(N, "-"));

  // A,Bを使ってresultを書き換える
  for (int i = 0; i < M; i++) {
    // A.at(i)-1, B.at(i)-1の要素を〇にする
    // B.at(i)-1, A.at(i)-1の要素を×にする
    result.at(A.at(i)-1).at(B.at(i)-1) = "o";
    result.at(B.at(i)-1).at(A.at(i)-1) = "x";
  }

  //　resultを出力
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << result.at(i).at(j);
      if (j == N-1) {
        cout << endl; // 末尾なら改行
      }
      else {
        cout << " ";  // それ以外なら空白
      }
    }
    
  }
}

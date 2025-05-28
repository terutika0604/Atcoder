#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
// #include <algorithm>


// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

vector<int> add_vec(vector<int> vec1, vector<int> vec2) {
  vector<int> result;
  for (int i = 0; i < vec1.size(); i++) {
    result.push_back(vec1.at(i) + vec2.at(i));
  }
  return result;
}

vector<int> sub_vec(vector<int> vec1, vector<int> vec2) {
  vector<int> result;
  for (int i = 0; i < vec1.size(); i++) {
    result.push_back(vec1.at(i) - vec2.at(i));
  }
  return result;
}

int main() {
  int N;
  cin >> N;

  // [int, x, =, 1, +, 2]
  // [print_int, x, +, 3]
  vector<vector<string>> O(N);

  rep(i, 0, N) {
    int j = 0;
    while (true) {
      string s;
      cin >> s;
      if (s == ";") break;
      O.at(i).push_back(s);
      j++;
    }
  }

  map<char, int> clc_result; // 変数名をキーにもつ計算結果格納メモリ
  map<char, vector<int>> clc_result_vec; // 変数名をキーにもつ計算結果格納メモリ

  rep(i, 0, N) {
    vector<string> term = O.at(i);

    if (term.at(0) == "int") {
      int x = 0;
      bool  next_ope_is_add = true;
      rep(j, 3, term.size()){
        if (isdigit(term.at(j)[0])) {
          // 数字が出てくるとき
          if (next_ope_is_add) x += stoi(term.at(j));
          else x -= stoi(term.at(j));
        }
        else {
          // 符号が出たらnext_ope_is_addを更新
          if (term.at(j) == "+") continue;
          if (term.at(j) == "-") {
            next_ope_is_add = false;
            continue;
          };
        }
      }
      clc_result[term.at(1)[0]] = x;
      continue;
    }

    if (term.at(0) == "print_int") {
      int x = 0;
      bool  next_ope_is_add = true;
      rep(j, 1, term.size()){
        auto c = term.at(j)[0];
        if (isdigit(c)) {
          // 数字が出てくるとき
          if (next_ope_is_add) x += stoi(term.at(j));
          else x -= stoi(term.at(j));
        }
        else {
          // 変数名が出たら変数を展開する
          if (next_ope_is_add) x += clc_result[term.at(j)[0]];
          else x -= clc_result[term.at(j)[0]];

          // 符号が出たらnext_ope_is_addを更新
          if (term.at(j) == "+") continue;
          if (term.at(j) == "-") {
            next_ope_is_add = false;
            continue;
          };
        }
      }
      cout << x << endl;
      continue;
    }

    if (term.at(0) == "vec") {
      vector<int> x;
      vector<int> another;
      
      bool next_ope_is_add = true;
      bool start_vec = false;
      rep(j, 3, term.size()){
        if (isdigit(term.at(j)[0])) {
          // 数字が出てくる&&[]の中にいるとき
          if(start_vec) x.push_back(stoi(term.at(j)));
          cout << "push" << endl;
        }
        else {
          // []が出たら[]の内外を判定する変数を更新
          cout << "no push" << endl;
          if (term.at(j) == "[") {
            start_vec = true;
            continue;
          };
          if (term.at(j) == "]") {
            start_vec = false;
            continue;
          };

          // 変数名が出たら変数を展開する
          // start_vec = true ➝ int項
          // start_vec = false ➝ vec項
          if (start_vec) x.push_back(clc_result[term.at(j)[0]]);
          else another = clc_result_vec[term.at(j)[0]];

          // 符号が出たらnext_ope_is_addを更新
          if (term.at(j) == "+") continue;
          if (term.at(j) == "-") {
            next_ope_is_add = false;
            continue;
          };
        }
      }
      if (next_ope_is_add && another.size() != 0) x = add_vec(x, another); 
      else x = sub_vec(x, another);
      
      cout << term.at(1)[0] << endl;
      // clc_result_vec[term.at(1)[0]] = x;
      continue;
    }

    if (term.at(0) == "print_vec") {
      print_vec(clc_result_vec.at(term.at(1)[0]));
    }

  }  
}

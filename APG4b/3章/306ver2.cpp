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

// 変数名を読み取りイコールを読み飛ばす
string read_name() {
  string v, eq;
  cin >> v >> eq;
  return v;
}

// int式の項を1つ読み取る。
// 数字ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
int read_int(map<string, int> &var_int) {
  string s;
  cin >> s;
  if (isdigit(s[0])) {
      return stoi(s);
  }
  else {
    return var_int[s];
  }
}

// int式全体を読み取って計算する
// var_int : intの変数を保持するmap
int calc_int(map<string, int> &var_int) {
  int total = 0;
  int i = 0;
  bool is_next_ope_add = true;
  while (true) {
    if (i % 2 == 0) {
      if (is_next_ope_add) total += read_int(var_int);
      else total -= read_int(var_int);
    }
    else {
      string s;
      cin >> s;
      if (s == "+") is_next_ope_add = true;
      if (s == "-") is_next_ope_add = false;
      if (s == ";") break;
    }
    i++;
  }
  
  return total;
}

// vec値を読み取る [ ~ ]
// 最初の"["は読み取ってある前提であることに注意
// var_int : intの変数を保持するmap
vector<int> read_vec_val(map<string, int> &var_int) {
  vector<int> result;
  int i = 0;
  while (true) {
    string s;
    cin >> s;
    if (s == "]") break;
    if (s == ",") continue;

    if (isdigit(s[0])) {
      result.push_back(stoi(s));
    }
    else {
      result.push_back(var_int[s]);
    }

    i++;
  }
  
  return result;
}

// vec式の項を1つ読み取る
// vec値ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
vector<int> read_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec) {

  string s;
  cin >> s;

  // []
  if (s == "[") return read_vec_val(var_int);

  // a
  return var_vec[s];
}

// vec式全体を読み取って計算する
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
vector<int> calc_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec) {
  vector<int> result;
  int i = 0;
  bool is_next_ope_add = true;
  while (true) {
    // 1文字目
    vector<int> vec = read_vec(var_int, var_vec);

    if(i == 0) {
      result = vec;
    } else {
      rep(j, 0, result.size()) {
        if(is_next_ope_add) result.at(j) += vec.at(j);
        else result.at(j) -= vec.at(j);
      }
    }
    
    // 2文字目
    string s;
    cin >> s;
    if (s == "+") is_next_ope_add = true;
    if (s == "-") is_next_ope_add = false;
    if (s == ";") break;
    
    i++;
  }

  return result;
}


int main() {

  // 命令の行数を取得
  int N;
  cin >> N;

  map<string, int> var_int; // intの変数を管理するmap
  map<string, vector<int>> var_vec; // vectorの変数を管理するmap

  // 行数分の処理
  for (int i = 0; i < N; i++) {

    // 命令を受け取る
    string s;
    cin >> s;
    
    // int命令の処理
    if (s == "int") {
      // 変数名を読み取る
      string name = read_name();
      // 右辺の式を計算して変数に代入
      var_int[name] = calc_int(var_int);
    }

    // vec命令の処理
    if (s == "vec") {
      // 変数名を読み取る
      string name = read_name();
      // 右辺の式を計算して変数に代入
      var_vec[name] = calc_vec(var_int, var_vec);
    }

    // print_int命令の処理
    if (s == "print_int") {
      // 式を計算して出力
      cout << calc_int(var_int) << endl;
    }

    // print_vec命令の処理
    if (s == "print_vec") {
      // 式を計算して出力
      print_vec(calc_vec(var_int, var_vec));
    }
  }
}

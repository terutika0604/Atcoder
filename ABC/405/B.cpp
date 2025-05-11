#include <bits/stdc++.h>
using namespace std;

bool check_conditions(vector<int> A, int M) {
  for (int j = 1; j < M + 1; j++) {
    bool id_included = false;
    for (size_t i = 0; i < A.size(); i++) {
      if (A.at(i) == j) id_included = true;
    }

    // Aには1以上M以下の整数がひとつでも含まれていない場合id_included = false ➝　check_conditionsはtrueを返す
    if(!id_included) {
      return true;
    };
  }

  return false;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int min_pop_count = 0;
  
  for (int i = 0; i < N; i++) {
    // 条件を満たす場合
    // Aには1以上M以下の整数がひとつでも含まれていない場合true
    if (check_conditions(A, M)) {
      cout << min_pop_count << endl;
      return 0;
    } else {
      A.pop_back();
      min_pop_count++;
    }
  }

  cout << min_pop_count << endl;
  
}

// 順列全探索
// ハミルトンパスの数え上げ

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;
// #include <algorithm>
// #include <iomanip>

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(M, vector<int>(2));

    rep(i, 0, M) rep(j, 0, 2) {
        cin >> a.at(i).at(j);
    }
    
    // 初期順列の生成
    vector<int> order(N);
    rep(i, 0 ,N) order.at(i) = i + 1;
    

    int counter = 0;
    do {
        if (order.at(0) != 1) continue;
        // 123 132 
        bool can = true;
        rep(ni, 0 , N - 1) { // 1→2 2→3　確認
            int now = min(order.at(ni), order.at(ni + 1)); //1
            int next = max(order.at(ni), order.at(ni + 1)); //2

            bool can2 = false;
            rep(mi, 0, M) { //aからリンクチェック
                if (a.at(mi).at(0) == now && a.at(mi).at(1) == next) {
                    // リンク存在
                    can2 = true;
                    break;
                }
            }
            // if リンクが存在しない場合can=false
            if (!can2) can = false;
        }

        if (can) counter++;
    } while (next_permutation(order.begin(), order.end()));
    
    cout << counter << endl;
    
    return 0;
}
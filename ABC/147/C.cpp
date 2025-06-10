// 不正解解答
// bit全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<vector<int>> X(N);
    vector<vector<int>> Y(N);

    rep(i, 0, N) {
        int a;
        cin >> a;
        A.at(i) = a;

        rep(j, 0, a) {
            int x, y;
            cin >> x >> y;
            X.at(i).push_back(x);
            Y.at(i).push_back(y);
        }
    }

    int max_honest = 0;

    for (int bit = 0; bit < (1 << N); bit++) {
        // 000 001 010 011 100 101 110 111 (3人目 2人目 1人目)
        int honest_num = 0;
        rep(i, 0, N) rep(j, 0, A.at(i)) {
            // //i人目のj個目の証言の整合性チェック
            if (bit & (1 << i)) { // i人目が正直者の時だけ検証する
                // cout << "bit is " << bit << endl;
                // cout << "i is " << i << endl;
                // cout << "j is " << j << endl;
                // cout << "Y.at(i).at(j) is " << Y.at(i).at(j) << endl; //ij
                // 00=1 10=1 20=0 cout << "X.at(i).at(j) is " << X.at(i).at(j)
                // << endl; //ij 00=2 10=1 20=2
                if (Y.at(i).at(j)) {
                    // y=1:xが正直
                    int honest_index = (N - 1) - (X.at(i).at(j) - 1);
                    if (bit != (1 << honest_index)) {
                        honest_num = 0;
                        continue;
                    }; // 矛盾発生
                } else {
                    // y=0:xが不親切
                    int not_honest_index = (N - 1) - (X.at(i).at(j) - 1);
                    if (bit != (0 << not_honest_index)) {
                        honest_num = 0;
                        continue;
                    }; // 矛盾発生
                }
                // 矛盾なし
                honest_num++;
                cout << "bit = " << bit << "j = " << j << endl;
            }
        }
        max_honest = max(max_honest, honest_num);
    }

    cout << max_honest << endl;

    return 0;
}
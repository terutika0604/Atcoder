// bit全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(M); //[{s11 s12 ..}, {s21 s22, ..} ... {sk1 skm}]
    vector<int> P(M);

    rep(i, 0, M) {
        int Km;
        cin >> Km;
        rep(j, 0, Km) {
            int sin = 0;
            cin >> sin;
            S.at(i).push_back(sin);
        }
    }

    rep(i, 0, M) {
        cin >> P.at(i);
    }

    int paturn_counter = 0;
    
    for (int bit = 0; bit < (1<<N); bit++) {
        vector<bool> paturn_checker(M, false);
        // int ok = 0; として
        
        rep(i, 0, M) {
            int on_light_counter = 0;
            // 各ライトに対する処理
            rep(j, 0, S.at(i).size()) {
                int bitpoint = S.at(i).at(j) - 1;
                //　各電球に紐づくスイッチが1になっている（ついているか）確認
                if (bit & (1 << bitpoint)) {
                    on_light_counter++;
                }
            }
            if (on_light_counter % 2 == P.at(i)) {
                paturn_checker.at(i) = true;
                // ok++として
            }
        }

        bool count_flag = true;
        // すべてのライトがonならカウントする
        rep(i, 0, M) {
            if(paturn_checker.at(i) == false) {
                count_flag = false;
            }
        }
        if(count_flag) paturn_counter++;
        // if(ok == M) paturn_counter++とすればより簡易的にかけたかも
    }

    cout << paturn_counter << endl;

    return 0;
}


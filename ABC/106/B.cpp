#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    // 「奇数かつ約数が 8 個」を満たす数
    int num_counter = 0;
    
    rep(i, 1, n + 1) {
        if (i % 2 == 0) continue; // 偶数を省く

        // 与えられた数の約数の個数
        int divisor_counter = 1;

        rep(j, 1, i) {
            if (divisor_counter > 8) break; // 約数が8個以上の場合は早期で打ち切る
            if (i % j == 0) {
                divisor_counter++;
            }
        }

        if (divisor_counter == 8) {
            num_counter++;
        }
    }

    cout << num_counter << endl;

    return 0;
}


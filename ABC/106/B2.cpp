// https://blog.hamayanhamayan.com/entry/2018/08/18/230559
// O(n)をO(squrt(n))に落とす回答
// 　約数問題

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int, int>;

vector<int> enumdiv(int n) {
    vector<int> S;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            S.push_back(i);
            if (i * i != n)
                S.push_back(
                    n /
                    i); // 例）n=36のとき1とともに36、2とともに18を約数として計上する
        }
    }
    sort(S.begin(), S.end());
    return S;
}

int main() {
    int n;
    cin >> n;

    // 「奇数かつ約数が 8 個」を満たす数
    int num_counter = 0;

    rep(i, 1, n + 1) if (i % 2 == 1) {
        auto ed = enumdiv(i);
        if (ed.size() == 8)
            num_counter++;
    }

    cout << num_counter << endl;

    return 0;
}

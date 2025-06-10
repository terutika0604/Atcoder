// 不正解解答
// 順列全探索にチャレンジ　→　TLE（N!×Nだからそれはそう）

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;
// #include <algorithm>
// #include <iomanip>

int main() {
    int N;
    cin >> N;
    vector<int> H(N), S(N);
    rep(i, 0, N) cin >> H.at(i) >> S.at(i);

    // 初期順列の生成
    vector<int> order(N);
    rep(i, 0, N) order.at(i) = i;

    ll min_max_result = 1000000000;

    do {
        ll max_result = 0;
        rep(i, 0, N) {
            // i[s]
            int balloon_index = order.at(i);
            ll result = H.at(balloon_index) + S.at(balloon_index) * i;
            max_result = max(max_result, result);
        }
        min_max_result = min(min_max_result, max_result);
    } while (next_permutation(order.begin(), order.end()));

    cout << min_max_result << endl;

    return 0;
}
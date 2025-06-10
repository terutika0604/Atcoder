// https://drken1215.hatenablog.com/entry/2021/06/12/113100
// 2分探索
// 最適化問題を判定問題に言い換える！ =
// すべての風船を高度x以内で割ることは可能か判定

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

    ll left = 0;
    ll right = 1LL << 60; // 2^60 64bitのうち60bitを使った十分に大きい値

    // 実現可能高度を２分探索する　実現可能高度midから算出されるデッドラインtを算出する
    while (right - left >
           1) { // 例）r=25, l=23でr-l>1ならmid=24の探索範囲が存在する
        ll mid = (left + right) / 2; // 実現可能高度
        vector<ll> t(N, 0); // 実現可能高度になる時間＝デッドライン
        bool ok = true; // 実現可能かどうかの判定

        rep(i, 0, N) {
            // 初期高度が実現可能高度より大きかったらfalse確定
            if (mid < H.at(i)) {
                ok = false;
                break;
            }
            t.at(i) = (mid - H.at(i)) / S.at(i); // x = H + S*t より算出
        }

        sort(t.begin(),
             t.end()); // tが小さい＝デッドライン到達までの時間が短い順に並べる

        rep(i, 0, N) {
            // i＝経過時間　経過時間がデッドラインより大きい＝実現不可能
            if (t.at(i) < i)
                ok = false;
        }

        // 実現可能であれば右を狭めてより小さい実現可能高度を探しにいく
        // 実現不可能であれば左を狭めてより大きい高度で実現可能か探しにいく
        if (ok)
            right = mid;
        else
            left = mid;
    }

    cout << right << endl;

    return 0;
}
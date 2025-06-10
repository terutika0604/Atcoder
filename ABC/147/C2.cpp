// https://blog.hamayanhamayan.com/entry/2019/12/13/214342

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
// #pragma GCC optimize ("-O3")
using namespace std;
void _main();
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int N;
vector<int> honests[15];
vector<int> liars[15];
void _main() {
    cin >> N;
    rep(i, 0, N) {
        int A;
        cin >> A;
        rep(j, 0, A) {
            int x, y;
            cin >> x >> y;
            // 不親切と正直者の配列を作る
            if (y == 0)
                liars[i].push_back(x - 1);
            else
                honests[i].push_back(x - 1);
        }
    }

    int ans = 0;
    rep(msk, 0, 1 << N) {
        bool ok = true;
        int tot = 0;
        rep(i, 0, N) if (msk & (1 << i)) { // 000 001 010 011 100 101 110 111
            // 正直者だけ検証する（考え方〇）
            tot++;
            fore(honest, honests[i]) if (!(msk & (1 << honest))) ok = false;
            fore(liar, liars[i]) if (msk & (1 << liar)) ok = false;
        }
        if (ok)
            chmax(ans, tot);
    }
    cout << ans << endl;
}
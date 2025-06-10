// 深さ優先探索
// imos法

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<ll> counter;

void dfs(const Graph &G, int v, int prev_v, const vector<ll> &X) {
    seen[v] = true;

    if (v == prev_v) {
        // 始点（根）の時の処理
        counter.at(v) += X.at(v);
    } else {
        // 親に加算した値を累積する
        counter.at(v) = X.at(v) + counter.at(prev_v);
    }

    for (auto next_v : G[v]) {
        if (seen[next_v])
            continue;
        dfs(G, next_v, v, X);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    Graph G(N);
    vector<ll> X(N, 0);

    rep(i, 0, N - 1) {
        int ni, mi;
        cin >> ni >> mi;
        G.at(ni - 1).push_back(mi - 1);
        G.at(mi - 1).push_back(ni - 1);
    }

    // rep(i, 0, N) {
    //     cout << "{ ";
    //     rep(j, 0, G.at(i).size()) {
    //         cout << G.at(i).at(j);
    //         cout << " ";
    //     }
    //     cout << "}";
    // }

    rep(i, 0, Q) {
        int p, x;
        cin >> p >> x;
        X.at(p - 1) += x;
    }

    counter.assign(N, 0);

    seen.assign(N, false);
    dfs(G, 0, 0, X);

    rep(i, 0, N) {
        cout << counter.at(i);
        if (i != N - 1) {
            cout << " ";
        }
    };
    cout << endl;
}
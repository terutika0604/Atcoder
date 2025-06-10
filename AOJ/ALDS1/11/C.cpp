// 幅優先探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;

    Graph G(n);
    vector<int> dist(n, -1);
    queue<int> que;

    rep(i, 0, n) {
        int u, k;
        cin >> u >> k;
        rep(j, 0, k) {
            int v;
            cin >> v;
            G.at(u - 1).push_back(v - 1);
        }
    }

    // 初期ノードを既読にしqueueに入れる
    dist.at(0) = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int next_v : G.at(v)) {
            if (dist.at(next_v) != -1)
                continue;

            dist.at(next_v) = dist.at(v) + 1;
            que.push(next_v);
        }
    }

    rep(i, 0, n) { cout << i + 1 << " " << dist.at(i) << endl; }
}
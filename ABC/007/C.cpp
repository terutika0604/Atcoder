#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int R, C;
    P start;
    P goal;

    cin >> R >> C;
    cin >> start.second >> start.first;
    cin >> goal.second >> goal.first;
    start.first--;
    start.second--;
    goal.first--;
    goal.second--;

    // 横軸C(x)、縦軸R(y) G.at(y).at(x)で要素にアクセス
    Graph G(R, vector<int>(C));
    vector<vector<bool>> seen(R, vector<bool>(C, false));
    queue<P> que; // (x, y)

    rep(i, 0, R) rep(j, 0, C) {
        char v;
        cin >> v;

        if (v == '#') {
            G.at(i).at(j) = -1;
        } else if (v == '.') {
            G.at(i).at(j) = 0;
        }
    }

    // rep(i, 0, R) {
    //     rep(j, 0, C) { cout << G.at(i).at(j); }
    //     cout << endl;
    // }

    // 初期ノードを既読にしqueueに入れる
    seen.at(start.second).at(start.first) = true;
    // G.at(start.second).at(start.first) = 0;
    que.push({start.first, start.second});

    int diff_x[] = {0, 0, 1, -1};
    int diff_y[] = {1, -1, 0, 0};

    while (!que.empty()) {
        P v = que.front();
        que.pop();

        rep(i, 0, 4) {
            int next_x = v.first + diff_x[i];
            int next_y = v.second + diff_y[i];

            // 壁(=-1)をはじく
            if (G.at(next_y).at(next_x) == -1)
                continue;

            // 既読をはじく
            if (seen.at(next_y).at(next_x))
                continue;

            seen.at(next_y).at(next_x) = true;
            G.at(next_y).at(next_x) = G.at(v.second).at(v.first) + 1;
            que.push({next_x, next_y});
        }
    }

    cout << G.at(goal.second).at(goal.first) << endl;
}
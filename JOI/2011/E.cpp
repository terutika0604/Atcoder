#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    // 入力をそのまま保存する配列
    vector<vector<char>> field(H, vector<char>(W));
    // スタート地点（最初は巣）の座標
    P start;
    // 工場の座標配列
    vector<P> factorise(N);

    rep(y, 0, H) rep(x, 0, W) {
        char c;
        cin >> c;
        field.at(y).at(x) = c;

        if (c == 'X')
            continue;
        if (c == '.')
            continue;
        if (c == 'S') {
            start.first = x;
            start.second = y;
            continue;
        }

        int fac_index = c - '0';
        factorise.at(fac_index - 1) = {x, y};
    }

    // マス間の上下左右への移動を定義する
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};

    int total_min = 0;

    // 工場の数分ループ
    rep(i, 0, N) {
        queue<P> que;
        vector<vector<int>> dist(H, vector<int>(W, -1));
        // 2周目以降はスタート地点の更新をかける
        if (i != 0) {
            start.first = factorise[i - 1].first;
            start.second = factorise[i - 1].second;
        }
        que.push(start);
        dist[start.second][start.first] = 0;

        // 幅優先探索
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int next_x = x + dx[dir];
                int next_y = y + dy[dir];

                // 新たなマスが場外の場合
                if (next_x < 0 || next_x >= W || next_y < 0 || next_y >= H)
                    continue;

                // 新たなマスが壁の場合
                if (field[next_y][next_x] == 'X')
                    continue;

                // 新たなマスが訪問済みの場合
                if (dist[next_y][next_x] != -1)
                    continue;

                que.push({next_x, next_y});
                dist[next_y][next_x] = dist[y][x] + 1;
            }
        }

        // rep(i, 0, H) {
        //     rep(j, 0, W) { cout << dist[i][j] << " "; }
        //     cout << endl;
        // }

        total_min += dist[factorise[i].second][factorise[i].first];
    }

    cout << total_min << endl;
}
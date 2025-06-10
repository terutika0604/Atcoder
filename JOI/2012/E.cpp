// 幅優先探索
// ハニカム

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int W, H;
    cin >> W >> H;

    Graph field(H + 2, vector<int>(W + 2, 0));
    rep(i, 1, H + 1) rep(j, 1, W + 1) { cin >> field[i][j]; }

    // 与えられた空間を縦横＋１拡張する
    // すべてのマスを既読をつけながら幅優先探索
    // ＝既読がつけられなかったマスが建物ブロック
    // 建物の辺のうち空白と隣接している辺を足し合わせる！！！

    // ハニカムの場合、偶奇で移動方向が異なる
    int dx_for_oddy[] = {0, -1, 0, 1, 1, 1};
    int dy_for_oddy[] = {-1, 0, 1, 1, 0, -1};
    int dx_for_eveny[] = {-1, -1, -1, 0, 1, 0};
    int dy_for_eveny[] = {-1, 0, 1, 1, 0, -1};

    queue<P> que;
    vector<vector<int>> seen(H + 2, vector<int>(W + 2, false));

    que.push({0, 0});
    seen[0][0] = true;

    // 幅優先探索
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int dir = 0; dir < 6; ++dir) {
            int next_x, next_y;
            if (y % 2 == 0) {
                next_x = x + dx_for_eveny[dir];
                next_y = y + dy_for_eveny[dir];
            } else {
                next_x = x + dx_for_oddy[dir];
                next_y = y + dy_for_oddy[dir];
            }

            // 新たなマスが場外の場合
            if (next_x < 0 || next_x >= W + 2 || next_y < 0 || next_y >= H + 2)
                continue;

            // 新たなマスが訪問済みの場合
            if (seen[next_y][next_x])
                continue;

            // 新たなマスが建物ありの場合
            if (field[next_y][next_x] == 1)
                continue;

            que.push({next_x, next_y});
            seen[next_y][next_x] = true;
        }
    }

    int total_edge = 0;

    // 既読が付いていないマスのうち、既読がついているマス（建物のないマス）と接している辺の数を数え上げる
    rep(yi, 1, H + 1) rep(xi, 1, W + 1) {
        if (seen[yi][xi])
            continue;

        for (int dir = 0; dir < 6; ++dir) {
            int next_x, next_y;
            if (yi % 2 == 0) {
                next_x = xi + dx_for_eveny[dir];
                next_y = yi + dy_for_eveny[dir];
            } else {
                next_x = xi + dx_for_oddy[dir];
                next_y = yi + dy_for_oddy[dir];
            }

            if (seen[next_y][next_x])
                total_edge++;
        }
    }

    cout << total_edge << endl;
}
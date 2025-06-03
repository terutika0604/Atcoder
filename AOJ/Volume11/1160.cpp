// 深さ優先探索

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = (int)(start); i < (int)(end); i++)
#define ll long long
#define Graph vector<vector<int>>

vector<vector<bool>> seen;

void dfs(vector<vector<vector<pair<int, int>>>> &G, int x, int y, int &cnt) {
  seen.at(y).at(x) = true;
  cnt++;
  // iから行ける各頂点 next_i について
  for (auto next_point : G.at(y).at(x)) {
    if (seen.at(next_point.second).at(next_point.first)) continue;
    dfs(G, next_point.first, next_point.second, cnt);
  }
}

void output_island_cnt(int x, int y) {
  Graph grid(y, vector<int>(x, 0));
  rep(yi, 0, y) rep(xi, 0, x) {
    int v;
    cin >> v;
    grid[yi][xi] = v;
  }

  // 移動可能な点の隣接リスト G[y][x]
  vector<vector<vector<pair<int, int>>>> G(y, vector<vector<pair<int, int>>>(x));
  // 移動方向（8方向）
  vector<pair<int, int>> diff = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
  
  rep(yi, 0, y) rep(xi, 0, x) {
    if (grid[yi][xi] == 0) continue;
    for (int dir = 0; dir < 8; ++dir) {
        int nx = xi + diff.at(dir).first;
        int ny = yi + diff.at(dir).second;
        if (0 <= nx && nx < x && 0 <= ny && ny < y && grid[ny][nx] == 1) {
            G[yi][xi].emplace_back(nx, ny);
        }
    }
  }

  // rep(yi, 0, y) rep(xi, 0, x) {
  //   cout << "(x, y) = " << xi << " " << yi << endl;
  //   rep(vi, 0, G[yi][xi].size()) {
  //     cout << G[yi][xi][vi].first << " " << G[yi][xi][vi].second << endl;
  //   }
  // }

  
  seen.assign(y, vector<bool>(x, false));

  int island_cnt = 0;

  rep(yi, 0, y) rep(xi, 0, x) {
    int cnt = 0;
    if (seen.at(yi).at(xi) || grid[yi][xi] == 0) continue;
    dfs(G, xi, yi, cnt);
    island_cnt++;
  }

  cout << island_cnt << endl;
}


int main() {
  
  while (true) 
  {
    int x, y;
    cin >> x >> y;

    if(x == 0 && y == 0) {
      break;
    }

    output_island_cnt(x, y);
  }
  
  
}
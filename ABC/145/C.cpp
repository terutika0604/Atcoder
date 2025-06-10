// 順列全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;
#include <algorithm>
#include <iomanip>

int main() {
    int N;
    cin >> N;

    vector<vector<int>> coordinate(N, vector<int>(N));
    rep(i, 0, N) rep(j, 0, 2) {
        // [[0,0], [0,1], [1.0]]
        cin >> coordinate.at(i).at(j);
    }
    
    // 初期順列の生成
    vector<int> order(N);
    //[0, 1, ... ,N-1]
    // 0 1 2 →　0 2 1
    rep(i, 0 ,N) order.at(i) = i;
    
    double sum_dist = 0;
    int sum_patturn = 0;

    do {
        rep(i, 0, N - 1) {
            int next_index = order.at(i + 1);
            int index = order.at(i);
 
            // sqrt(x^2+y^2) = dist
            int distx = (coordinate.at(next_index).at(0) - coordinate.at(index).at(0));
            int disty = (coordinate.at(next_index).at(1) - coordinate.at(index).at(1));

            double dist = sqrt(distx * distx + disty * disty);
            sum_dist += dist;
        }
        sum_patturn++;
    } while (next_permutation(order.begin(), order.end()));
    
    cout << fixed << setprecision(10) << sum_dist / sum_patturn << endl;
    
    return 0;
}
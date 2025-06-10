// 順列全探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;
// #include <algorithm>
// #include <iomanip>

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Q(N);

    rep(i, 0, N) {
        cin >> P.at(i);
    }
    rep(i, 0, N) {
        cin >> Q.at(i);
    }
    
    // 初期順列の生成
    vector<int> order(N);
    rep(i, 0 ,N) order.at(i) = i + 1;
    
    int a = 0, b = 0;
    int counter = 0;

    do {
        if(P == order) a = counter;
        if(Q == order) b = counter;
        counter++;
    } while (next_permutation(order.begin(), order.end()));
    
    cout << abs(a - b) << endl;
    
    return 0;
}
// 2分探索(lower_bound, upper_bound)
// 3つのものを考えるときは、真ん中を固定して考える

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
    vector<int> A(N), B(N), C(N);
    rep(i, 0, N) cin >> A.at(i);
    rep(i, 0, N) cin >> B.at(i);
    rep(i, 0, N) cin >> C.at(i);
    
    ll counter = 0;

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    // Bを全探索
    rep(i, 0, N) {
        int mid = B.at(i);
        ll num_a = lower_bound(A.begin(), A.end(), mid) - A.begin(); //mid以下のAの個数
        ll num_c = N - (upper_bound(C.begin(), C.end(), mid) - C.begin()); //mid以上のCの個数

        counter += num_a * num_c;
    }

    cout << counter << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;
#include <string>

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> a_div = {}, b_div = {}, ab_div = {};

    rep(i, 1, a + 1) {
        if(a % i != 0) continue;
        a_div.push_back(i);
    }
    rep(i, 1, b + 1) {
        if(b % i != 0) continue;
        b_div.push_back(i);
    }

    for (int ad : a_div) {
        for (int bd : b_div) {
            if(ad == bd) {
                ab_div.push_back(ad);
            }
        }
    }
    

    cout << ab_div.at( ab_div.size() - k ) << endl;

    return 0;
}
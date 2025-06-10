#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    rep(i, 1, 10) {
        if(n % i == 0) {
            int syou  = n / i;
            if (syou < 10) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
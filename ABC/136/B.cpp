#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    int counter = 0;
    rep(i, 1, n + 1) {
        int s_length = to_string(i).length();
        if (s_length % 2 == 0) continue;
        counter++;
    }

    cout << counter << endl;

    return 0;
}
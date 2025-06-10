#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int counter = 0;

    rep(i, 0, n) {
        char first = s[i];
        char second = s[i+1];
        char third = s[i+2];
        if (first != 'A') continue;
        if (second != 'B') continue;
        if (third != 'C') continue;
        counter++;
    }

    cout << counter << endl;

    return 0;
}
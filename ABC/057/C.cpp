// 約数問題　longlongを理解するためのいい問題

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;

    int min_fout = 1000000000;

    for (ll i = 1; i * i < n + 1; i++) {
        if (n % i != 0 ) continue;

        string str1 = to_string(i);
        string str2 = to_string(n/i);

        // int fout = str1.size() > str2.size() ? str1.size() : str2.size();
        int fout = max(str1.size(), str2.size());

        // min_fout = min_fout > fout ? fout : min_fout;
        min_fout = min(fout,min_fout);

    }

    cout << min_fout << endl;

    return 0;
}


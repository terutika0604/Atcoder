#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;
#include <string>

int main() {
    string s;
    cin >> s;

    string acgt = "ACGT";
    int max_counter = 0;
    int counter = 0;

    rep(i, 0, s.length()) {
        auto result = acgt.find(s.at(i));
        if (result == string::npos) {
            max_counter = counter > max_counter ? counter : max_counter;
            counter = 0;
            continue;
        }
        counter++;
    }

    max_counter = counter > max_counter ? counter : max_counter;

    cout << max_counter << endl;

    return 0;
}
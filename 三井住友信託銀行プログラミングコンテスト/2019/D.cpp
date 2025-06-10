#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;
#include <string>

bool cannotRemoveChar(string &lnum, char point) {
    string::size_type find_index = lnum.find(point);
    if (find_index == string::npos) {
        return true;
    } else {
        lnum.erase(0, find_index + 1);
        return false;
    }
}

int main() {
    int digit;
    string lnum;
    cin >> digit >> lnum;

    set<string> pins = {};

    // n^3の全探索はTLE
    // rep(i1, 0, digit) rep(i2, i1 + 1, digit) rep(i3, i2 + 1, digit) {
    //     string pin = string(1, lnum.at(i1)) + string(1, lnum.at(i2)) + string(1, lnum.at(i3));
    //     pins.insert(pin);
    // }

    // 000 ~ 999までループ
    rep(i1, 0, 10) {
        rep(i2, 0, 10) {
            rep(i3, 0, 10) {
                string copy_lnum = lnum;
                if(cannotRemoveChar(copy_lnum, to_string(i1)[0])) continue;
                if(cannotRemoveChar(copy_lnum, to_string(i2)[0])) continue;
                if(cannotRemoveChar(copy_lnum, to_string(i3)[0])) continue;
                string pin = to_string(i1) + to_string(i2) + to_string(i3);
                pins.insert(pin);
            }
        }
    }

    cout << pins.size() << endl;
    

    return 0;
}
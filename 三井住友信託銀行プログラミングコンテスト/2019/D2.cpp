// 林君の回答

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 1000; ++i) {
        string pin = to_string(i);
        while (pin.size() < 3) {
            pin = "0" + pin;
        }
        int j = 0;
        for (auto c : s) { // 123123 C=1 000~099スルー → 100~ ++j → C=2
            if (c == pin[j]) {
                if (++j == 3) { // インクリメントされたjが3になるまで繰り返す
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
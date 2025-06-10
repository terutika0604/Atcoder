// 2分探索

#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
using ll = long long;
using P = pair<int,int>;
// #include <algorithm>
// #include <iomanip>

int main() {
    int n, q;
    
    cin >> n;
    vector<int> S(n);
    rep(i, 0, n) cin >> S.at(i);

    cin >> q;
    vector<int> T(q);
    rep(i, 0, q) cin >> T.at(i);

    
    int counter = 0;

    rep(i, 0, q) {
        int search_num = T.at(i);

        int start_index = 0;
        int end_index = S.size() - 1;

        while (end_index >= start_index) {
            int middle_index = (start_index + end_index) / 2; // Sの中央のインデックス 
    
            if (S.at(middle_index) == search_num) {
                counter++;
                break;
            } else if(S.at(middle_index) > search_num) {
                end_index = middle_index - 1;
            } else if(S.at(middle_index) < search_num) {
                start_index = middle_index + 1;
            }
        }
    }
    
    cout << counter << endl;
    
    return 0;
}
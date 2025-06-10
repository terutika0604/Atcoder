#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i < (int)(end); i++)
using ll = long long;
using P = pair<int,int>;
#include <string>

int main() {
    int price_A, price_B, price_C, num_of_A, num_of_B;
    cin >> price_A >> price_B >> price_C >> num_of_A >> num_of_B;

    ll min_sum = 1000000000;

    int num_max = max(num_of_A, num_of_B);

    for (int i = 0; i < num_max + 1; i++) {
        ll sum = 0;
        sum += price_C * i * 2; // AB
        if(num_of_A - i > 0) {
            sum += price_A * (num_of_A - i); // A
        }
        if(num_of_B - i > 0) {
            sum += price_B * (num_of_B - i); //B
        }
        min_sum = min(min_sum, sum);
    }
    cout << min_sum << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        ll num = N;
        int d;
        ll rev = 0;
        while (num > 0) {
            d = num % 10;
            rev = rev*10 + d;
            num = num / 10;
        }
        if (rev == N) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

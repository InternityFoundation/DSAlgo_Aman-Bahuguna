#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                cout << int(s[i] - 64);
            } else if (s[i] >= 97 && s[i] <= 122) {
                cout << int(s[i] - 96);
            } else {
                cout << "$";
            }
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int i = 0;
        int j = s.size() - 1;
        bool flag = true;
        while (i < j) {
            if (s[i] != s[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

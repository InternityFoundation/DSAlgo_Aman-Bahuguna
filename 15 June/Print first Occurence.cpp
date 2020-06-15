#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string arr;
        cin >> arr;
        unordered_map<char, int> seen;
        for (int i = 0; i < arr.size(); i++) {
            if (seen.count(arr[i]) > 0) {
            continue;
            }
            seen[arr[i]]++;
            cout << arr[i];
        }
        cout << endl;
    }
}

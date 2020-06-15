#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> seen;
    vector<char> v;
    for (int i = 0; i < n; i++) {
        char key = s[i];
        if (seen.count(key) == 0) {
            seen[key] = 1;
            v.push_back(key);
            continue;
        }
        seen[key]++;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}

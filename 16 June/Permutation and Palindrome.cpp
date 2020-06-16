#include <bits/stdc++.h>
using namespace std;

char getChar(int i) {
    return (char)(i + 97);
}

void print(string s) {
    map<char, vector<int>> indexes;
    for (int i = 0; i < s.size(); i++) {
        indexes[s[i]].push_back(i);
    }
    int freq = 0;
    for (int i = 0; i < 26; i++) {
        if ((indexes[getChar(i)].size() % 2) != 0) {
            freq++;
        }
    }
    if (freq >= 2) {
        cout << "-1";
        return;
    }
    int ans[s.size()];
    int start = 0;
    int end = s.size() - 1;
    for (int i = 0; i < 26; i++) {
            char curr = getChar(i);
            for (int j = 0; j < indexes[curr].size(); j+=2) {
            if ((indexes[curr].size() - j) == 1) {
                ans[s.size()/2] = indexes[curr][j];
                continue;
            }
            ans[start] = indexes[curr][j];
            ans[end] = indexes[curr][j+1];
            start++;
            end--;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
}

int main() {
	int T;
	cin >> T;
	while (T--) {
	    string s;
	    cin >> s;
	    print(s);
	    cout << endl;
	}

	return 0;
}


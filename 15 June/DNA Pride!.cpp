#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        char arr[1000000];
        cin >> arr;
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (arr[i] == 'A') {
                arr[i] = 'T';
            }
            else if (arr[i] == 'T') {
                arr[i] = 'A';
            }
            else if (arr[i] == 'G') {
                arr[i] = 'C';
            }
            else if (arr[i] == 'C') {
                arr[i] = 'G';
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << arr << "\n";
        } else {
            cout << "Error RNA nucleobases found!" << "\n";
        }
    }
}

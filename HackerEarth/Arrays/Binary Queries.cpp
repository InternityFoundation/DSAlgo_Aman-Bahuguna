#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int x;
    while (Q--) {
        int x;
        cin >> x;
        if (x == 0) {
            int l, r;
            cin >> l >> r;
            if (arr[r - 1] == 0) {
                cout << "EVEN" << endl;
            } else {
                cout << "ODD" << endl;
            }
        } else {
            int y;
            cin >> y;
            arr[y - 1]  = arr[y - 1] ^ 1;
        }
    }
    return 0;
}

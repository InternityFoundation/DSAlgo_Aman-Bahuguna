#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        int ans = 0;
        if (K < A[0]) {
            ans = 0;
        } else {
             ans = K - A[0];
        }
        cout << ans << endl;
    }
}

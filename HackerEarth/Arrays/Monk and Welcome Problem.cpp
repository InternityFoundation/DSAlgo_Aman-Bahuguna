#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    cout.precision(10);
    int N;
    cin >> N;
    int A[100000];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int B[100000];
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int C[100000];
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
        cout << C[i] << " ";
    }
    return 0;
}

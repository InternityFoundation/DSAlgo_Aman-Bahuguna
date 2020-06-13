#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[1000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int best_so_far = INT_MIN;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= best_so_far) {
            v.push_back(arr[i]);
            best_so_far = arr[i];
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

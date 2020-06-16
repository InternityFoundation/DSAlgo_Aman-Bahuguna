#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    queue<ll> q;
    int count = 0;
    int end = n - 1;
    
    while (m--) {
        int curr;
        cin >> curr;
        ll ans;
        for (; count < curr; count++) {
            if (end >= 0 && (q.empty() || arr[end] >= q.front())) {
                ans = arr[end];
                end--;
            } else {
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout << ans << "\n";
    }
    return 0;
}

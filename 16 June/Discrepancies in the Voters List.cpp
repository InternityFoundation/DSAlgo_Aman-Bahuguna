#include <bits/stdc++.h>
using namespace std;

vector<int> getAns(int* arr, int N) {
    sort(arr, arr + N);
    vector<int> v;
    for (int i = 0; i < N;) {
        int count = 0;
        int j = i;
        while (j < N && (arr[i] == arr[j])) {
            count++;
            j++;
        }
        if (count >= 2) {
            v.push_back(arr[i]);
        }
        i = j;
    }
    return v;
}

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int N = n1 + n2 + n3;
	int arr[N];
	for (int i = 0; i < N; i++) {
	    cin >> arr[i];
	}
	vector<int> v = getAns(arr, N);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
	    cout << v[i] << "\n";
	}
	return 0;
}

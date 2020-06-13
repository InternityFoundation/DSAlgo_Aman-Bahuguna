#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(char* arr) {
    int len = strlen(arr);
    stack<int> s;
    for (int i = 0; i < len; i++) {
        char exp = arr[i];
        if (exp == '(' || exp == '{' || exp == '[') {
            s.push(exp);
        }
        else if (exp == ')' || exp == '}' || exp == ']') {
            if (s.empty()) {
                return false;
            }
            char curr = s.top();
            s.pop();
            if (curr == '(' && exp == ')') {
                continue;
            }
            else if (curr == '{' && exp == '}') {
                continue;
            }
            else if (curr == '[' && exp == ']') {
                continue;
            }
            else {
                return false;
            }
        }
    }
    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char arr[1001];
        cin >> arr;
        if (isBalanced(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

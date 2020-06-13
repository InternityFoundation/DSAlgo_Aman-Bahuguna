#include <iostream>
#include <vector>
using namespace std;

vector<int> funGame (vector<int> arr) {
   vector<int> out;
   int nA = 0, nB = arr.size() - 1;
   while (nA < arr.size() && nB >= 0) {
      if(arr[nA] > arr[nB]) {
         out.push_back(1);
         nB--;
      } else if (arr[nA] < arr[nB]) {
         out.push_back(2);
         nA++;
      } else {
         out.push_back(0);
         nA++;
         nB--;
      }
   }
   return out;
}

int main() {
   ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = funGame(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}

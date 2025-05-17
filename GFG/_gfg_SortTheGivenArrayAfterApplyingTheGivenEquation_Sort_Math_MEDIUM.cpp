#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
          for(int i = 0 ; i<arr.size();i++){
            int x = arr[i];
            int res =  (A*(x*x)) + (B*x) + C;
            arr[i] = res;
        }
        sort(arr.begin(),arr.end()); 
        return arr;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {1, 2, 3, 4};
    int A = 1, B = 2, C = 3;
    vector<int> result = obj.sortArray(arr, A, B, C);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
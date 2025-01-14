#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int sum = 0,l_sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        for(int i=0;i<arr.size();i++){
            sum -= arr[i];
            if(sum == l_sum){
                return i;
            }
            l_sum += arr[i];
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1, 2, 0, 3};
    cout<<s.findEquilibrium(arr);
}
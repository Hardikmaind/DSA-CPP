#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int left = 0, right = arr.size() - 1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left + k;
        
    }
};
int main(){
    int k=1;
    vector<int> arr={2,3,5,9,10};
    Solution obj;
    cout<<obj.kthMissing(arr,k);        //ans is 1
    return 0;
}
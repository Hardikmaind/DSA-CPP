#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          // code here
           int l = 0, r = arr.size() - 1;
  
          while (l <= r) {
              int mid = l + (r - l) / 2;
      
              // Handle edge cases for mid
              if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
                  (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                  return arr[mid];
              } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                  // We are in the decreasing part
                  r = mid - 1;
              } else {
                  // We are in the increasing part
                  l = mid + 1;
              }
          }
      
          return -1;
          
          // OR below ONE LINER SOLUTION
          
          // return *max_element(arr.begin(),arr.end());
      }
  };


  int main(){
    Solution obj;
    vector<int> arr = {1, 3, 8, 12, 4, 2};
    cout << obj.findMaximum(arr) << endl; // Output: 12
    return 0;
  }
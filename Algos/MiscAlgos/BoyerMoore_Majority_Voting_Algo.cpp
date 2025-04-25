#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          // code here
           int candidate = -1, count = 0;
  
          // Step 1: Find the candidate
          for (int num : arr) {
              if (count == 0) {
                  candidate = num;
              }
              count += (num == candidate) ? 1 : -1;
          }
      
          // Step 2: Verify the candidate
          count = 0;
          for (int num : arr) {
              if (num == candidate) count++;
          }
      
          return (count > arr.size() / 2) ? candidate : -1;
          
      }
      
  };



  int main(){
    Solution obj;
    vector<int>arr={1,1,2,1,3,1,5};
    int result = obj.majorityElement(arr);
    cout<<result;
    return 0;
  }
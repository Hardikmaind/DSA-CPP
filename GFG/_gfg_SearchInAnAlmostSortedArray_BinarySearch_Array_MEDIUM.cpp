#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int l=0;
          int r=arr.size()-1;
          while(l<=r){
              int mid=l+(r-l)/2;
              if(arr[mid]==target){
                  return mid;
              }else if(arr[mid+1]==target){
                  return mid+1;
              }else if(arr[mid-1]==target){
                  return mid-1;
              }
              
              
              if(arr[mid]>target){
                  r=mid-1;
              }else{
                  l=mid+1;
              }
              
          }
          return -1;
          
      }
  };


  int main(){
    Solution obj;
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 40;
    int result = obj.findTarget(arr, target);
    cout<<result<<endl; // Output: 3

    return 0;
  }
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr.size()-1;
        int count=0;
        
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum<target){
                l++;
                count+=r-l+1;
            }else{
                r--;
                
            }    
        }
        return count;
    }
};

int main(){
    Solution obj;
    vector<int> arr={2, 1, 8, 3, 4, 7, 6, 5};
    int target=7;
    cout<<obj.countPairs(arr,target);
}
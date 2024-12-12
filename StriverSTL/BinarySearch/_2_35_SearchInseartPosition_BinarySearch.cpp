#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=nums.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target){
                ans=mid;
                r=mid-1;
            }else{

                l=mid+1;
            }
        }
        
        return ans;
    }
};
int main(){

    vector<int> arr={1,3,5,6};
    int m=5;
    Solution obj;
    cout<<obj.searchInsert(arr,m)<<endl;
    return 0;
    
}
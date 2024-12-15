#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//! THIS IS APPRAOCH 1
    static int findFirst(vector<int>&nums,int &target){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target){
                ans=mid;
                r=mid-1;

            }else{
                l=mid+1;
            }
        }
        return (ans != -1 && nums[ans] == target) ? ans : -1;
    }
    static int findLast(vector<int>&nums,int &target){
          int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return (ans != -1 && nums[ans] == target) ? ans : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return{findFirst(nums,target),findLast(nums,target)};
    }

//! THIS IS APPRAOCH 2 with the help of the lower_bound and upper_bound
    vector<int> searchRange2(vector<int>& nums, int target) {
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==r){       //* this means if the element is not present in the array,the l and r will go out of the array. then we will return the {-1,-1}
            return {-1,-1};
        }
        return {l,r-1};     // here we are returning the l and r-1 because the upper_bound returns the next element of the target element,so we are subtracting 1 from the r.
    }
};




int main(){
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=s.searchRange(nums,target);
    vector<int> ans2=s.searchRange2(nums,target);


    cout<<ans[0]<<" "<<ans[1]<<endl;
    cout<<ans2[0]<<" "<<ans2[1]<<endl;
}
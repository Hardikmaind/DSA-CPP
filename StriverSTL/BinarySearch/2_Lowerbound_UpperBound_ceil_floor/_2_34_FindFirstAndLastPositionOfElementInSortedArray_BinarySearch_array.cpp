#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
};

int main(){
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=s.searchRange(nums,target);


    cout<<ans[0]<<" "<<ans[1]<<endl;
}
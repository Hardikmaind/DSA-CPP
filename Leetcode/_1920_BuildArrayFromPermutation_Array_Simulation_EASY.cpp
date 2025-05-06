#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int>res(nums.size());
            for(int i=0;i<nums.size();i++){
                res[i]=nums[nums[i]];
            }
            return res;
        }
    };


    int main(){
        Solution s;
        vector<int> nums = {0,2,1,5,3,4};
        vector<int> result = s.buildArray(nums);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        return 0;
    }
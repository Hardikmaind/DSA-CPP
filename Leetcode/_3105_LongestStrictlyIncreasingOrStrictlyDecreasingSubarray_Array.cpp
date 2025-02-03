#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlength=1;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                count++;
                maxlength=max(maxlength,count);

            }else{
                count=1;
            }
        }
        int maxlength2=1;
         count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                count++;
                maxlength2=max(maxlength2,count);

            }else{
                count=1;
            }
        }
        return max(maxlength2, maxlength);
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    cout << s.longestMonotonicSubarray(nums);
    return 0;
}
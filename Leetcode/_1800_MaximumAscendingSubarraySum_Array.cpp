#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                sum+=nums[i];
                maxSum=max(sum,maxSum);
            }else{
                sum=nums[i];
            }
        }
        return maxSum;
    }
};

int main(){
    Solution a;
    vector<int> nums = {10,20,30,5,10,50};
    cout << a.maxAscendingSum(nums) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long res = 0;
            for (int k = 2; k < n; k++) {
                int maxPrefix = nums[0];
                for (int j = 1; j < k; j++) {
                    res = max(res, (long long)(maxPrefix - nums[j]) * nums[k]);
                    maxPrefix = max(maxPrefix, nums[j]);
                }
            }
            return res;
        }
    };

    int main(){
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        Solution obj;
        cout<<obj.maximumTripletValue(nums)<<endl;
        return 0;
    }
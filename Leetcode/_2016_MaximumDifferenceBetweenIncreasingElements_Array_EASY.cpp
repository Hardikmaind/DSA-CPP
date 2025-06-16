#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {7, 1, 5, 4};
    cout << sol.maximumDifference(nums) << endl; // Output: 4
    return 0;
}
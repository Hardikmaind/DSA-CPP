#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/solutions/6623686/0-1-knapsack-dp-with-images-example-walkthrough-c-python-java

class Solution {
    public:
    //! tc O(n * targetSum) sc O(targetSum)
        //! 1D DP array
        bool canPartition(vector<int>& nums) {
            int totalSum = 0;
            for (int num : nums) totalSum += num;
    
            if (totalSum % 2 != 0) return false;
    
            int targetSum = totalSum / 2;
            vector<bool> dp(targetSum + 1, false);
            dp[0] = true;
            for (int num : nums) {
                for (int currSum = targetSum; currSum >= num; --currSum) {
                    dp[currSum] = dp[currSum] || dp[currSum - num];
                    if (dp[targetSum]) return true;
                }
            }
            return dp[targetSum];
        }
    };


    int main(){
        Solution sol;
        vector<int> nums = {1, 5, 11, 5};
        cout << (sol.canPartition(nums) ? "true" : "false") << endl; // Output: true
        return 0;
    }
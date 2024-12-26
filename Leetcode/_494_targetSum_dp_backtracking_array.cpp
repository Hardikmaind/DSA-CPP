#include <bits/stdc++.h>
using namespace std;

//! this is the brute force solution

class Solution1 {
public:
    int totalWays = 0;  // Tracks the total number of ways to reach the target

    int findTargetSumWays(std::vector<int>& nums, int target) {
        calculateWays(nums, 0, 0, target);
        return totalWays;
    }

private:
    void calculateWays(std::vector<int>& nums, int currentIndex, int currentSum,
                       int target) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                totalWays++;
            }
        } else {
            // Include the current number with a positive sign
            calculateWays(nums, currentIndex + 1,
                          currentSum + nums[currentIndex], target);
            // Include the current number with a negative sign
            calculateWays(nums, currentIndex + 1,
                          currentSum - nums[currentIndex], target);
        }
    }
};



//! this is the recursion with the memoization solution

class Solution2 {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
        return calculateWays(nums, 0, 0, target, memo);
    }

    int calculateWays(vector<int>& nums, int currentIndex, int currentSum,
                      int target, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            // Check if the result is already computed
            if (memo[currentIndex][currentSum + totalSum] !=
                numeric_limits<int>::min()) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add =
                calculateWays(nums, currentIndex + 1,
                              currentSum + nums[currentIndex], target, memo);

            // Calculate ways by subtracting the current number
            int subtract =
                calculateWays(nums, currentIndex + 1,
                              currentSum - nums[currentIndex], target, memo);

            // Store the result in memoization table
            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
};

//! this is the 2D dp solution

class Solution3 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));

        // Initialize the first row of the DP table
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] +=
                        dp[index - 1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] +=
                        dp[index - 1][sum + totalSum];
                }
            }
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0
                                      : dp[nums.size() - 1][target + totalSum];
    }
};


//! this is space optimized version of above solution
class Solution4 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * totalSum + 1, 0);

        // Initialize the first row of the DP table
        dp[nums[0] + totalSum] = 1;    // Adding nums[0]
        dp[-nums[0] + totalSum] += 1;  // Subtracting nums[0]

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            vector<int> next(2 * totalSum + 1, 0);
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};


int main(){
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s1.findTargetSumWays(nums, target) << endl;
    cout << s2.findTargetSumWays(nums, target) << endl;
    cout << s3.findTargetSumWays(nums, target) << endl;
    cout << s4.findTargetSumWays(nums, target) << endl;
    return 0;
}
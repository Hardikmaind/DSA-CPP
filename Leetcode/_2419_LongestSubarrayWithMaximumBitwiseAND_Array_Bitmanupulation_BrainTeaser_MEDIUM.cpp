#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 2, 1, 3};
    cout << "Longest subarray with maximum bitwise AND: " << solution.longestSubarray(nums) << endl;
    return 0;
}
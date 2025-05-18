#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // Build sorted target array with (digitSum, value)
        vector<pair<int, int>> sorted;
        for (int num : nums) {
            sorted.emplace_back(digitSum(num), num);
        }
        // Sort by digit sum, then value
        sort(sorted.begin(), sorted.end());
        // Map original value to its final index in sorted
        unordered_map<int, int> valueToSortedIndex;
        for (int i = 0; i < n; ++i) {
            valueToSortedIndex[sorted[i].second] = i;
        }
        // Build visited array and count cycles
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || valueToSortedIndex[nums[i]] == i)
                continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = valueToSortedIndex[nums[j]];
                cycleSize++;
            }
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }return swaps;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {18,43,34,16};
    cout << sol.minSwaps(nums) << endl; // Output: 0
    return 0;
}
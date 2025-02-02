#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/6336062/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // Construct the rotated array
        vector<int> checkSorted(n);

        // Iterate through all possible rotation offsets
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = (nums[index]);
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = (nums[index]);
            }

            // Check if the constructed array is sorted
            bool isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }

            // If sorted, return true
            if (isSorted) {
                return true;
            }
        }

        // If no rotation makes the array sorted, return false
        return false;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,4,5,1,2};
    cout<<obj.check(nums);
    return 0;
}
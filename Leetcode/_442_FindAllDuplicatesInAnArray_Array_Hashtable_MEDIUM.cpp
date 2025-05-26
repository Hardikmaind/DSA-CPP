#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;

            if (nums[index] < 0) {
                // Already visited → duplicate
                result.push_back(abs(nums[i]));
            } else {
                // Mark as visited
                nums[index] = -nums[index];
            }
        }

        return result;  
    }
};

int main(){
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = solution.findDuplicates(nums);
    
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    vector<vector<int>> result = sol.divideArray(nums, k);
    
    if (result.empty()) {
        cout << "No valid division possible." << endl;
    } else {
        for (const auto& group : result) {
            cout << "[";
            for (int num : group) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;  // unjudged minimum index
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int key = 3;
    int k = 1;
    vector<int> result = sol.findKDistantIndices(nums, key, k);
    
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
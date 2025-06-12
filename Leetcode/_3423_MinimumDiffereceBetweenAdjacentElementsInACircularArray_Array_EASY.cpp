#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxdiff=max(INT_MIN,abs(nums.front()-nums.back()));
        for(int i=1;i<nums.size();i++){
            maxdiff=max(maxdiff,abs(nums[i]-nums[i-1]));
        }        
        return maxdiff;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 3, 6, 10, 15};
    cout << "Maximum adjacent distance: " << sol.maxAdjacentDistance(nums) << endl;
    return 0;
}
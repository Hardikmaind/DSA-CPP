#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int l=0,r=0;
      int maxsum=0;
      int sum=0;
      unordered_set<int>set;
      while(r<nums.size()){
        while(set.count(nums[r])>0){
            set.erase(nums[l]);
            sum-=nums[l];
            l++;

        }
        set.insert(nums[r]);
        sum+=nums[r];
        maxsum=max(maxsum,sum);
        r++;

      }
      return maxsum;

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << sol.maximumUniqueSubarray(nums) << endl; // Output: 17
    return 0;
}
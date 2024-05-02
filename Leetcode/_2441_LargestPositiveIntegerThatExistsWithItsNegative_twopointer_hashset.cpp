#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int findMaxK(std::vector<int> &nums)
        {
            std::set<int> s;
            for (int &x: nums)
            {
                s.insert(x);
            }
            int largestK = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0 && s.count(-nums[i]))
                {
                    largestK = std::max(largestK, nums[i]);
                }
            }
            return largestK != INT_MIN ? largestK : -1;
        }
};
int main(){
    Solution sol;
    std::vector<int> nums = {3, 2, 1, 5, 4, 6, 7, 8, 9, 10,-10};
    std::cout << sol.findMaxK(nums) << std::endl;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;

// do brute force with simple for loop, that code i have written in the java, check java repo

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long totpairs = (long long)n * (n - 1) / 2;
        unordered_map<long long, long long> hm;
        long long goodpairs = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            hm[nums[i] - i]++;
        }
        for (auto x : hm)
        {
            goodpairs += (long long)(x.second) * (x.second - 1) / 2;
        }
        return totpairs - goodpairs;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.countBadPairs(nums);
    cout<<endl;

    vector<int> nums2 = {4, 1, 3, 3};
    cout << sol.countBadPairs(nums2);

    return 0;
}
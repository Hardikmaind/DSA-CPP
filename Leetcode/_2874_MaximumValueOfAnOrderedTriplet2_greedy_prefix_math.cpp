#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for (int j = 1; j < n - 1; j++)
        {
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {12,6,1,2,7};
    Solution obj;
    long long res = obj.maximumTripletValue(nums);
    cout << res << endl; // Output: 6
    Solution2 obj2;
    res = obj2.maximumTripletValue(nums);
    cout << res << endl; // Output: 6
    
    return 0;

}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n)*(n+1)/2;        
        for(auto &x:nums){
            sum-=x;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])      //this main function takes parameter as command line arguments.best practice to use in competitive programming. because it is faster to take the input.
{
    Solution s;
    vector<int> nums={9,6,4,2,3,5,7,0,1};
    cout<<s.missingNumber(nums)<<endl;
    return 0;
}






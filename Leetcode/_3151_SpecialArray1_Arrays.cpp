#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                return false;
            }
        }
        return true;

    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,4};
    cout<<boolalpha<<s.isArraySpecial(nums);
    return 0;
}
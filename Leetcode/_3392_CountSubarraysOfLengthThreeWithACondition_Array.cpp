#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int count=0;
            for(int i=0;i<nums.size()-2;i++){
                if(nums[i+1]==(nums[i]+nums[i+2])*2){
                    count++;
                }
            }
            return count;
        }
    }; 

    int main(){
        Solution obj;
        vector<int> nums = {1,2,1,4,1};

        cout << obj.countSubarrays(nums) << endl; // Output: 0
        return 0;
    }
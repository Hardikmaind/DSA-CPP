#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            unordered_map<int,int>prefix;
            prefix[0]=1;
            int sum=0;
            int count=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(prefix.count(sum-goal)>0){
                    count+=prefix[sum-goal];
                }
                prefix[sum]++;
            }
            return count;
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,0,1,0,1};
        int goal=2;
        cout<<s.numSubarraysWithSum(nums,goal)<<endl;
        return 0;
    }
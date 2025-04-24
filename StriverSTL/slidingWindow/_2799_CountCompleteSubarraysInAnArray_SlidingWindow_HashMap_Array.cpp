#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int>hm;
            for(auto &x :nums){
                hm[x]++;
            }
            int distinctele=hm.size();
            hm.clear();
            int l=0,r=0,n=nums.size();
            int count=0;
            while(r<n){
                hm[nums[r]]++;
                while(hm.size()==distinctele){
                    count+=n-r;
                    hm[nums[l]]--;
                    if(hm[nums[l]]==0){
                        hm.erase(nums[l]);
                    }
                    l++;
                }
                r++;
    
            }
            return count;
            
        }
    };


    int main(){
        Solution obj;
        vector<int> nums = {1,3,1,2,2};
        int result = obj.countCompleteSubarrays(nums);
        cout<<result;
        return 0;
    }
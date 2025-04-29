#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            long long count=0;
            int l=0;
            int r=0;
            int n=nums.size();
            if(n<k){
                return 0;
            }
            int temp=k;
            int maxele=*max_element(nums.begin(),nums.end());
            int freq=0;
            while(r<n){
                if(nums[r]==maxele){
                    freq++;
                }
                while(freq>=k){
                    count+=n-r;
                    if(nums[l]==maxele){
                        freq--;
                    }
                    
                    l++;
                }
                r++;
            }
            return count;
        }
    };


    class Solution2 {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            long long count=0;
            int l=0;
            int r=0;
            int n=nums.size();
            if(n<k){
                return 0;
            }
            int temp=k;
            int maxele=*max_element(nums.begin(),nums.end());
            unordered_map<int,int>hm;
            while(r<n){
                hm[nums[r]]++;
                
                while(hm[maxele]>=k){
                    count+=n-r;
                    hm[nums[l]]--;
                    if (hm[nums[l]] == 0) {
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
        Solution sol;
        Solution2 sol2;
        vector<int> nums = {1,3,2,3,3};
        int k = 2;
        cout << sol.countSubarrays(nums, k) << endl; 
        cout << sol2.countSubarrays(nums, k) << endl; 
        return 0;
    }
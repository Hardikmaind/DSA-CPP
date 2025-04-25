#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> prefix;
            prefix[0] = 1; // empty prefix
    
            long long ans = 0;
            int count = 0;
    
            for (int num : nums) {
                if (num % modulo == k) count++;
                int mod_val = ((count - k) % modulo + modulo) % modulo;//map[(count[i] + modulo - k) % modulo]
                ans += prefix[mod_val];
                prefix[count % modulo]++;
            }
    
            return ans;
        }
    };

    
    int main(){
        Solution obj;
        vector<int> nums = {1, 2, 3, 4, 5};
        int modulo = 2;
        int k = 1;
        cout << obj.countInterestingSubarrays(nums, modulo, k) << endl; // Output: 6
        return 0;
    }
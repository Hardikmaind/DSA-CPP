#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int count = 0;
            int i = 0;
            int n = nums.size();
            
            while (i < n) {
                unordered_set<int> seen;
                bool hasDuplicate = false;
                for (int j = i; j < n; ++j) {
                    if (seen.count(nums[j])) {
                        hasDuplicate = true;
                        break;
                    }
                    seen.insert(nums[j]);
                }
    
                if (!hasDuplicate) break;
    
                // Chop off 3 from the start
                count++;
                i += 3;
            }
    
            return count;
        }
    };

    
    int main(){
        Solution s;
        vector<int>arr={1,2,3,4,2,3,3,5,7};
        cout<<s.minimumOperations(arr)<<endl;
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> firstMap, secondMap;
            int n = nums.size();
    
            // Add all elements of nums to second half
            for (auto& num : nums) {
                secondMap[num]++;
            }
    
            for (int index = 0; index < n; index++) {
                // Create split at current index
                int num = nums[index];
                secondMap[num]--;
                firstMap[num]++;
    
                // Check if valid split
                if (firstMap[num] * 2 > index + 1 &&
                    secondMap[num] * 2 > n - index - 1) {
                    return index;
                }
            }
    
            // No valid split exists
            return -1;
        }
    };
    int main(){
        Solution s;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        cout << s.minimumIndex(nums) << endl;
        return 0;
    }
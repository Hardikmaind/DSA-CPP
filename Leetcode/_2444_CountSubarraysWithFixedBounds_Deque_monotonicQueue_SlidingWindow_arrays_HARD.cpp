#include <bits/stdc++.h>
using namespace std;



//! this is a brute force solution, O(n^2) time complexity, O(1) space complexity
class Solution2 {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long count = 0;
            for (int i = 0; i < nums.size(); i++) {
                int mini = INT_MAX, maxi = INT_MIN;
                for (int j = i; j < nums.size(); j++) {
                    mini = min(mini, nums[j]);
                    maxi = max(maxi, nums[j]);
                    if (mini == minK && maxi == maxK) ++count;
                }
            }
            return count;
        }
};


class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
                int n = nums.size();
            long long res = 0;
            int last_invalid = -1;   // index of last element outside [minK, maxK]
            int last_min = -1;       // last index where nums[i] == minK
            int last_max = -1;       // last index where nums[i] == maxK
    
            for (int i = 0; i < n; ++i) {
                if (nums[i] < minK || nums[i] > maxK) {
                    last_invalid = i;
                }
                if (nums[i] == minK) {
                    last_min = i;
                }
                if (nums[i] == maxK){
                    last_max = i;
                } 
    
                int valid_start = min(last_min, last_max);
                if (valid_start > last_invalid) {
                    res += valid_start - last_invalid;
                }
            }
            return res;
        }
    };

        //! above sol can be written in a more compact way like below
class Solution3 {
    public:
            long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long count = 0, start = -1, mini = -1, maxi = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < minK || nums[i] > maxK) start = i;
                if (nums[i] == maxK) maxi = i;
                if (nums[i] == minK) mini = i;
                int valid = max(0L, min(mini, maxi) - start);
                count += valid;
            }
            return count;
        }
    };


    //? MONOTONIC QUEUE SOLUTION
    //! double ended queue solution, O(n) time complexity, O(n) space complexity

class Solution4 {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long count = 0, left = 0;
            deque<int> dq_min, dq_max;
    
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < minK || nums[i] > maxK) {
                    dq_min.clear();
                    dq_max.clear();
                    left = i + 1;
                    continue;
                }
    
                while (!dq_min.empty() && nums[dq_min.back()] >= nums[i]) dq_min.pop_back();
                dq_min.push_back(i);
    
                while (!dq_max.empty() && nums[dq_max.back()] <= nums[i]) dq_max.pop_back();
                dq_max.push_back(i);
    
                if (nums[dq_min.front()] == minK && nums[dq_max.front()] == maxK) {
                    int start = min(dq_min.front(), dq_max.front());
                    count += (start - left + 1);
                }
            }
            return count;
        }
    };


int main(){
    Solution sol;
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;
    cout << sol.countSubarrays(nums, minK, maxK) << endl; // Output: 2
    return 0;
}
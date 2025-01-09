#include <bits/stdc++.h>
using namespace std;

//! THIS IS HASHMAP BASED  AND PREFIX SUM BASED SOLUTION. TC: O(N) SC: O(N)
class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int start = 0, sum = 0;
        
        for (int end = 0; end < arr.size(); ++end) {
            sum += arr[end]; // Expand the window by including arr[end]
            
            // Shrink the window until the sum is less than or equal to the target
            while (sum > target && start <= end) {
                sum -= arr[start];
                ++start;
            }
            
            // Check if the current window matches the target
            if (sum == target) {
                return {start + 1, end + 1}; // Return 1-based indices
            }
        }
        
        // If no subarray is found, return -1
        return {-1};
    }
};

//! THIS IS SLIDING WINDOW BASED SOLUTION. TC: O(N) SC: O(1)

class Solution2 {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        unordered_map<int, int> prefixMap; // Stores prefix sums and their indices
        int prefixSum = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];
            
            // Check if the subarray starting from index 0 satisfies the condition
            if (prefixSum == target) {
                return {1, i + 1}; // 1-based indexing
            }
            
            // Check if removing a prefix sum gives the required target
            if (prefixMap.find(prefixSum - target) != prefixMap.end()) {
                return {prefixMap[prefixSum - target] + 2, i + 1};
            }
            
            // Store the current prefix sum with its index
            prefixMap[prefixSum] = i;
        }
        
        // If no subarray is found, return -1
        return {-1};
    }
};



int main(){
    Solution s;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> ans = s.subarraySum(arr, target);
    for(auto x: ans){
        cout<<x<<" ";
    }

    cout<<endl;
    Solution2 s2;
    vector<int> arr2 = {1, 2, 3, 7, 5};
    int target2 = 12;
    vector<int> ans2 = s2.subarraySum(arr2, target2);
    for(auto x: ans2){
        cout<<x<<" ";
    }
}
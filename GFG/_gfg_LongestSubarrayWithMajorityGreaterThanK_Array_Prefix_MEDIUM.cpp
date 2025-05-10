#include <bits/stdc++.h>
using namespace std;
/*
! Goal:
We want the longest subarray with more +1s than -1s, i.e., net positive sum.
We use a prefix sum array, and:
* If at position j, the prefixSum[j] - prefixSum[i-1] > 0, then subarray (i to j) has a positive sum.
So if at position j, current prefixSum = P, and we want P - prefixSum[i-1] > 0, then:
prefixSum[i-1] < P
That means if we previously saw a smaller value than P, especially P - 1, then the subarray from that earlier index + 1 to j has positive sum.

*/

class Solution {
public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Transform array to +1/-1
        for (auto &x : arr) {
            x = (x > k) ? 1 : -1;
        }

        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = -1; // prefix 0 is at index -1 (important!)
        
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if (prefixSum > 0) {
                maxLen = i + 1; // whole array from 0 to i has positive sum
            } else {
                // Check if prefixSum - 1 was seen before
                if (first_occurrence.find(prefixSum - 1) != first_occurrence.end()) {
                    maxLen = max(maxLen, i - first_occurrence[prefixSum - 1]);
                }
            }

            // Store first occurrence only
            if (first_occurrence.find(prefixSum) == first_occurrence.end()) {
                first_occurrence[prefixSum] = i;
            }
        }

        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 1};
    int k = 2;
    cout << sol.longestSubarray(arr, k) << endl; // Output: 5
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int sum = 0;
        long count = 0;
        unordered_map<int, int> hm;
        hm[0] = 1; // To handle cases where the subarray starts at index 0
    
        for (int x : arr) {
            sum = sum ^ x;
    
            // Check if there is a prefix sum that matches the required condition
            if (hm.count(sum ^ k)) {
                count += hm[sum ^ k];
            }
    
            // Update the hash map with the current prefix sum
            hm[sum]++;
        }
    
        return count;
    }
};
int main(){
    Solution s;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout<<s.subarrayXor(arr, k);
}
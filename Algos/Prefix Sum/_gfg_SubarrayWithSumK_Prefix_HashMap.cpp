#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
    int sum = 0;
    int count = 0;
    unordered_map<int, int> hm;
    hm[0] = 1; // To handle cases where the subarray starts at index 0

    for (int x : arr) {
        sum += x;

        // Check if there is a prefix sum that matches the required condition
        if (hm.count(sum - k)) {
            count += hm[sum - k];
        }

        // Update the hash map with the current prefix sum
        hm[sum]++;
    }

    return count;
}

};
int main(){
    Solution s;
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout<<s.countSubarrays(arr, k);
}
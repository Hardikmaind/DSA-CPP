#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> res;
        unordered_map<int, int> freqMap;  // Map to store frequency of elements in the window
        int n = arr.size();

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        
        // Store the count of distinct elements for the first window
        res.push_back(freqMap.size());

        // Slide the window from left to right
        for (int i = k; i < n; i++) {
            // Add the current element to the window
            freqMap[arr[i]]++;
            
            // Remove the element that is left behind as the window slides
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]);
            }
            
            // Add the count of distinct elements in the current window
            res.push_back(freqMap.size());
        }
        
        return res;
    }
};


int main(){
    Solution obj;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> res = obj.countDistinct(arr, k);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}
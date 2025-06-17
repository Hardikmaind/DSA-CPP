#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = INT_MAX;
        vector<int> pre(n + 1, 0);
        
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + arr[i - 1];
        
        for (int i = 0; i < n; ++i) {
            int high = arr[i] + k;
            int ub = upper_bound(arr.begin(), arr.end(), high) - arr.begin();
            int cost = pre[i] + (pre[n] - pre[ub]) - (n - ub) * high;
            ans = min(ans, cost);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    cout << sol.minimumCoins(arr, k) << endl; // Example usage
    return 0;
}
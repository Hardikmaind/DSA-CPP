#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        vector<int> right(n);
        vector<int> stack;
        for (int i = 0; i < n; i++)
            right[i] = i;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[i] < arr[stack.back()]) {
                right[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int r = right[i];
            if (r == i) {
                dp[i] = (n - i) * arr[i];
            } else {
                dp[i] = (r - i) * arr[i] + dp[r];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(){
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << sol.sumSubMins(arr) << endl; // Output: 17
    return 0;
}
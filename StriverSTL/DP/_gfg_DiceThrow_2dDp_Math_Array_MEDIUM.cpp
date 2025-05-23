#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

        // Base case: one way to get sum 0 with 0 dice
        dp[0][0] = 1;
    
        // Fill the table
        for (int dice = 1; dice <= n; ++dice) {
            for (int sum = 1; sum <= x; ++sum) {
                for (int face = 1; face <= m; ++face) {
                    if (sum - face >= 0)
                        dp[dice][sum] += dp[dice - 1][sum - face];
                }
            }
        }
    
        return dp[n][x];
    }
};

int main(){
    Solution obj;
    int m = 6, n = 3, x = 8;
    cout << obj.noOfWays(m, n, x) << endl; // Output: 21
    m = 6, n = 2, x = 7;
    cout << obj.noOfWays(m, n, x) << endl; // Output: 6
    return  0;
}
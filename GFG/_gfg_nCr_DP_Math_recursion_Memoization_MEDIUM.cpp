#include <bits/stdc++.h>
using namespace std;


//! tc is O(n)
class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        r = std::min(r, n - r);
        long long res = 1;

        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
        }

        return (int)res;
    }

    
};
class Solution2 {
  public:
    int binomialCoeff(int n, int k) {
        vector<int> dp(k + 1);

        // nC0 is 1
        dp[0] = 1; 

        for (int i = 1; i <= n; i++) {
        
            // Compute next row of pascal triangle using
            // the previous row
            for (int j = min(i, k); j > 0; j--)
                dp[j] = dp[j] + dp[j - 1];
        }
        return dp[k];
    }

    
};
class Solution3 {
  public:
    int binomialCoeff(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1));
    
        // Calculate value of Binomial Coefficient
        // in bottom up manner
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
            
                // Base Cases
                if (j == 0 || j == i)
                    dp[i][j] = 1;

                // Calculate value using previously
                // stored values
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp[n][k];
    }

    
};
class Solution4 {
  public:
    int getnCk(int n, int k, vector<vector<int>> &memo) {
    
        // k can not be grater then k so we
        // return 0 here
        if (k > n)
            return 0;
    
        // base condition when k and n are 
        // equal or k = 0
        if (k == 0 || k == n)
            return 1;
        
        // Check if pair n and k is already 
        // calculated then return it from here
        if(memo[n][k] != -1) return memo[n][k];
    
        // Recurvie add the value and store to memorize table
        return memo[n][k] = getnCk(n - 1, k - 1, memo) 
                            + getnCk(n - 1, k, memo);
    }
    int binomialCoeff(int n, int k) {
        
        // Create table for memorization
        vector<vector<int>> memo(n + 1, vector<int> (k + 1, -1));
    
        return getnCk(n, k, memo);
    }

    
};



int main(){
    int n = 5, r = 2;
    Solution sol;
    cout << "Using iterative method: " << sol.nCr(n, r) << endl;

    Solution2 sol2;
    cout << "Using DP with 1D array: " << sol2.binomialCoeff(n, r) << endl;

    Solution3 sol3;
    cout << "Using DP with 2D array: " << sol3.binomialCoeff(n, r) << endl;

    Solution4 sol4;
    cout << "Using memoization: " << sol4.binomialCoeff(n, r) << endl;

    return 0;
}
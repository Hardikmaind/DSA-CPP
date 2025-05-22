#include <bits/stdc++.h>
using namespace std;


//! Intuition: find the longest palindromic subsequence (LPS) of the string. then subtract the length of LPS from the length of the string to get the minimum number of deletions required to make it a palindrome.
//! Approach: Use dynamic programming to find the length of the longest palindromic subsequence. Create a 2D array dp where dp[i][j] represents the length of the longest palindromic subsequence in the substring s[i..j]. Initialize dp[i][i] = 1 for all i. Then fill the table using the following rules:
class Solution {
public:
    static int minDeletions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Substrings of length 1 are palindromes of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Build the table for substrings of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;

                if (s[start] == s[end]) {
                    if (len == 2)
                        dp[start][end] = 2; // Pair of matching characters
                    else
                        dp[start][end] = dp[start + 1][end - 1] + 2;
                } else {
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }

        // Minimum deletions = total length - length of longest palindromic subsequence
        return n - dp[0][n - 1];
    }
};


int main(){
    string s = "geeksforgeeks";
    cout << Solution::minDeletions(s) << endl; // Output: 1
    return 0;
}
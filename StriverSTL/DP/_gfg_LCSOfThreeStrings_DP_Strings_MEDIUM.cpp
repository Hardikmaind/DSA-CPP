#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lcsOf3(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1, 0)));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= o; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    } else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
            }
        }

        return dp[m][n][o];
    }
};

int main(){
    Solution sol;
    string s1 = "abcd1e2";
    string s2 = "bc12ea";
    string s3 = "bd1ea";
    
    int result = sol.lcsOf3(s1, s2, s3);
    cout << "Length of LCS of three strings: " << result << endl; // Output: 2
    return 0;
}
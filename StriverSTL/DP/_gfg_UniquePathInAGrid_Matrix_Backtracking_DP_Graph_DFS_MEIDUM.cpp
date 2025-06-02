#include <bits/stdc++.h>
using namespace std;


//! this is recursion and backtracking solution to find the unique paths in a grid. tc is O(2^(m+n)) and sc is O(m+n) for the recursion stack
//? it can be optimised using dp or memoization to O(m*n) time and space complexity. see solution2
class Solution {
  public:
    void dfs2(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& mat,int &count){
        if(i == mat.size() - 1 && j == mat[0].size() - 1 && mat[i][j] != 1) {
            count++;
            return;
        }

        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]==1 || vis[i][j]) return;
        vis[i][j]=1;
        dfs2(i+1,j,vis,mat,count);
        dfs2(i,j+1,vis,mat,count);
        vis[i][j]=0;
        return ;
        

    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
          
          
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs2(0,0,vis,grid,count);
        return count;
        
    }
};

//! this is a dynamic programming solution to find the unique paths in a grid. it uses a 2D dp array to store the number of unique paths to each cell.
//? tc is O(m*n) and sc is O(m*n) for the dp array.
class Solution2 {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;  // Start cell

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) continue; // Blocked cell

                if (i > 0) dp[i][j] += dp[i - 1][j]; // From top
                if (j > 0) dp[i][j] += dp[i][j - 1]; // From left
            }
        }

        return dp[n - 1][m - 1]; // Ways to reach bottom-right
    }
};


int main(){
    Solution obj;
    vector<vector<int>>grid={{0,0,0},{0,1,0},{0,0,0}};
    int result = obj.uniquePaths(grid);
    cout<<result; // Output: 2

    cout<<endl;
    Solution2 obj2;
    vector<vector<int>>grid2={{0,0,0},{0,1,0},{0,0,0}};
    int result2 = obj2.uniquePaths(grid2);
    cout<<result2; // Output: 2

    return 0;
}
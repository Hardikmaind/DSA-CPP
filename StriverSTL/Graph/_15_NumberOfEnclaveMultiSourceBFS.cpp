#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // * THIS IS THE EASY DFS WHEN GRAPH IS GIVEN IN THE FORM OF THE GRID OR MATRIX
        void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &mat){
            if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]!=1 || vis[i][j]) return;
            vis[i][j]=1;
            dfs(i+1,j,vis,mat);
            dfs(i-1,j,vis,mat);
            dfs(i,j+1,vis,mat);
            dfs(i,j-1,vis,mat);
        }

        //! THIS IS ANOTHER WAY TO DO THE DFS, THIS USED THE DX AND DY DIRECTIONAL VECTORS.
        void dfs2(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& mat){
            vis[i][j]=1;
            int dx[]={0,1,0,-1};
            int dy[]={1,0,-1,0};
            int n=mat.size();
            int m=mat[0].size();
            for(int k=0;k<4;k++){
                int deltaX=i+dx[k];
                int deltaY=j+dy[k];
                if( deltaX>=0 && deltaX<n && deltaY>=0 && deltaY<m && mat[deltaX][deltaY]==1 && !vis[deltaX][deltaY] ){
                    dfs2(deltaX,deltaY,vis,mat);
                }
            }
        }

  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
              if(grid[i][0]==1 && !vis[i][0]){
                  dfs(i,0,vis,grid);
              }
              if(grid[i][m-1]==1 && !vis[i][m-1]){
                  dfs(i,m-1,vis,grid);
              }
          }
          for(int j=0;j<m;j++){
              if(grid[0][j]==1 && !vis[0][j]){
                  dfs(0,j,vis,grid);
              }
              if(grid[n-1][j]==1 && !vis[n-1][j]){
                  dfs(n-1,j,vis,grid);
              }
          }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};



int main(){
    Solution obj;
    vector<vector<int>> grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<obj.numberOfEnclaves(grid)<<endl;
    return 0;
}
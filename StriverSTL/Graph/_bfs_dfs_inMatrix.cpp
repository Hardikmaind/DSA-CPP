#include <bits/stdc++.h>
using namespace std;


class Solution {

    public:
    //! this is m1 with the help of recursion and backtracking
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0)return;
        
        vis[i][j] = 1;
    
        dfs(i+1, j, vis, grid);
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);
    }
    

    //! this is M2 with the help of directional vectors
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
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
    
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
    
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
    
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
    
                if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1 && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    

    

    
};


int main(){
    Solution obj;
    vector<vector<int>>grid={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    vector<vector<int>>grid2={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    vector<vector<int>>grid3={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};

    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    obj.bfs(0,0,vis,grid);
    
    for(auto &x:vis){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
   
    vector<vector<int>>vis1(n,vector<int>(m,0));
    obj.dfs(0,0,vis1,grid2);
    for(auto &x:vis1){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>>vis2(n,vector<int>(m,0));
    obj.dfs2(0,0,vis2,grid3);
    for(auto &x:vis2){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
}
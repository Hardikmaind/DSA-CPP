#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid,int row0,int col0,vector<pair<int,int>>&vec){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 ||j>=m|| vis[i][j]|| grid[i][j]!=1)return;
        vis[i][j]=1;
        vec.push_back({i-row0,j-col0});
        dfs(i+1,j,vis,grid,row0,col0,vec);
        dfs(i-1,j,vis,grid,row0,col0,vec);
        dfs(i,j+1,vis,grid,row0,col0,vec);
        dfs(i,j-1,vis,grid,row0,col0,vec);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> set;             //! here we cannot create unordered_set of vector<pair<int,int>>. that is why create a set 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs( i,j,vis,grid,i,j,vec);         //* here i have passes the inital row and col values . since we are subtracting the initial row and col from the pair values
                    set.insert(vec);
                }
            }
        }
        return set.size();
    }
};


int main(){
    Solution obj;
    vector<vector<int>>grid={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    int result = obj.countDistinctIslands(grid);
    cout<<result;
}
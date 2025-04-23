#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find distance of nearest 1 in the grid for each cell.
      vector<vector<int>> nearest(vector<vector<int>>& grid) {
          // Code here
          int n=grid.size();
          int m=grid[0].size();
          vector<vector<int>>vis(n,vector<int>(m,0));
          vector<vector<int>>dist(n,vector<int>(m,0));
          queue<pair<pair<int,int>,int>>q;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(grid[i][j]==1){
                      q.push({{i,j},0});
                      vis[i][j]=1;
                  }else{
                      vis[i][j]=0;
                      
                  }
              }
          }
          int dx[]={0,1,0,-1};
          int dy[]={1,0,-1,0};
          while(!q.empty()){
              auto ele=q.front();
              int x=ele.first.first;
              int y=ele.first.second;
              int step=ele.second;
              q.pop();
              dist[x][y]=step;
              
              for(int i=0;i<4;i++){
                  int deltaX=x+dx[i];
                  int deltaY=y+dy[i];
                  if(deltaX>=0 && deltaX<n && deltaY>=0 &&deltaY<m && grid[deltaX][deltaY]==0 && !vis[deltaX][deltaY]){
                      vis[deltaX][deltaY]=1;
                      q.push({{deltaX,deltaY},step+1});
                  }
              }
          }
          return dist;
      }
  };


  int main(){
    Solution obj;
    vector<vector<int>> grid={{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    auto res=obj.nearest(grid);
    for(auto &x:res){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout << endl;
    }
    return 0;
  }
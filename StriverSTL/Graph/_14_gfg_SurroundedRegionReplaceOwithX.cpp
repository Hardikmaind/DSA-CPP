#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //! for dfs this uses the directional vectors dx and dy
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& mat){
        vis[i][j]=1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int n=mat.size();
        int m=mat[0].size();
        for(int k=0;k<4;k++){
            int deltaX=i+dx[k];
            int deltaY=j+dy[k];
            if( deltaX>=0 && deltaX<n && deltaY>=0 && deltaY<m && mat[deltaX][deltaY]=='O' && !vis[deltaX][deltaY] ){
                dfs(deltaX,deltaY,vis,mat);
            }
        }
    }

    //! we can also do dfs in a matrix like this instead of using the dx and dy direction vectors.
    void dfs2(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& mat){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]!='O' || vis[i][j]) return;
        vis[i][j]=1;
        dfs2(i+1,j,vis,mat);
        dfs2(i-1,j,vis,mat);
        dfs2(i,j+1,vis,mat);
        dfs2(i,j-1,vis,mat);
    
    }
      vector<vector<char>> fill(vector<vector<char>>& mat) {
          // code here
          // here we dont change the og matrix(data) so we will create the new matrix
          int n=mat.size();
          int m=mat[0].size();
          
          
          vector<vector<int>>vis(n,vector<int>(m,0));
          for(int i=0;i<n;i++){
              if(mat[i][0]=='O' && !vis[i][0]){
                  dfs(i,0,vis,mat);
              }
              if(mat[i][m-1]=='O' && !vis[i][m-1]){
                  dfs(i,m-1,vis,mat);
              }
          }
          for(int j=0;j<m;j++){
              if(mat[0][j]=='O' && !vis[0][j]){
                  dfs(0,j,vis,mat);
              }
              if(mat[n-1][j]=='O' && !vis[n-1][j]){
                  dfs(n-1,j,vis,mat);
              }
          }
          
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(mat[i][j]=='O' && !vis[i][j]){
                      mat[i][j]='X';                              // here we can also do to diff matrix, by not changing the original matix
                  }
              }
          }
          return mat;
      }
  };



int main(){
    Solution obj;

    vector<vector<char>>mat={{'O','O','O','O'},{'O','X','X','O'},{'O','X','X','O'},{'O','O','O','O'}};
    auto res=obj.fill(mat);
    for(auto &x:res){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
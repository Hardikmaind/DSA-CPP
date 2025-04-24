#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&mat){
            vis[x][y]=1;
            int n=mat.size();
            int m=mat[0].size();
            int dx[]={0,1,0,-1};
            int dy[]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int deltaX=x+dx[i];
                int deltaY=y+dy[i];
                if(deltaX>=0 && deltaX<n && deltaY>=0 && deltaY<m && !vis[deltaX][deltaY]&& mat[deltaX][deltaY]=='O'){
                    dfs(deltaX,deltaY,vis,mat);
                }
            }
        }    
    public:
        void solve(vector<vector<char>>& board) {
            int n=board.size();
            int m=board[0].size();
            vector<vector<int>> vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                if(board[i][0]=='O'&& !vis[i][0]){
                    dfs(i,0,vis,board);
                }
                if(board[i][m-1]=='O'&& !vis[i][m-1]){
                    dfs(i,m-1,vis,board);
                }
            }
            for(int j=0;j<m;j++){
                if(board[0][j]=='O'&& !vis[0][j]){
                    dfs(0,j,vis,board);
                }
                if(board[n-1][j]=='O'&& !vis[n-1][j]){
                    dfs(n-1,j,vis,board);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O' && !vis[i][j]){
                        board[i][j]='X';
                    }
                }
            }
            
            
        }
    };


    int main(){
        Solution obj;
        vector<vector<char>> board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        obj.solve(board);
        for(auto &x:board){
            for(auto &y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
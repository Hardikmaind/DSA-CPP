#include <bits/stdc++.h>
using namespace std;


// ! THIS IS A bfs VERSION

class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int totIslands=0;
            int dx[4] = {0, 0, 1, -1, };
            int dy[4] = {1, -1, 0, 0, };;
            queue<pair<int,int>>q;
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        q.push({i,j});
                        grid[i][j]='0';
                        totIslands++;
                        while(!q.empty()){
                            auto temp=q.front();
                            q.pop();
                            for(int k=0;k<4;k++){
                                int dirx=temp.first+dx[k];
                                int diry=temp.second+dy[k];
                                if(dirx>=0 && dirx<n && diry<m && diry>=0 &&  grid[dirx][diry] == '1'){
                                    grid[dirx][diry]='0';
                                    q.push({dirx,diry});
                                }
                            }
                        }
                    }
                }
            }
            return totIslands;
        }
    };
class Solution2 {
    public:
            void dfs(int i, int j, vector<vector<char>>& grid, vector<int>& vis, int m, int n) {
                vis[i * m + j] = 1;

                int dx[4] = {0, 0, 1, -1};
                int dy[4] = {1, -1, 0, 0};

                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        grid[ni][nj] == '1' && !vis[ni * m + nj]) {
                        dfs(ni, nj, grid, vis, m, n);
                    }
                }
            }

            int numIslands(vector<vector<char>>& grid) {
                int n = grid.size();
                if (n == 0) return 0;
                int m = grid[0].size();

                vector<int> vis(n * m, 0);
                int totIslands = 0;

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (grid[i][j] == '1' && !vis[i * m + j]) {
                            dfs(i, j, grid, vis, m, n);
                            totIslands++;
                        }
                    }
                }
                return totIslands;
            }
    };
class Solution3 {
    public:
            void dfs(vector<vector<char>>& grid, int i, int j) {
                if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()  || grid[i][j] != '1') {
                    return;
                }
                grid[i][j] = '0';           //! we mark is as visited . or we make it as water so we dont go on it again

                dfs(grid, i + 1, j);        //* pehle ye pura i+1 , i+1 ,i+1 jayega, pura khatam karega, then ye pura j+1, j+1, j+1 jayega,then pura i-1,i-1,i-1 jayega and so on.
                dfs(grid, i, j + 1);
                dfs(grid, i - 1, j);
                dfs(grid, i, j - 1);
            }

            int numIslands(vector<vector<char>>& grid) {
                int count = 0;
                for (int i = 0; i < grid.size(); i++) {
                    for (int j = 0; j < grid[0].size(); j++) {
                        if (grid[i][j] == '1') {
                            dfs(grid, i, j);
                            count++;
                        }
                    }
                }
                return count;
            }
    };

    int main(){
        Solution s;
        vector<vector<char>>grid={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
        
        auto res=s.numIslands(grid);
        cout<<res<<endl;


        vector<vector<char>>grid2={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
        cout<<s.numIslands(grid2)<<endl;


        Solution2 s2;
        vector<vector<char>>grid3={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
        cout<<s2.numIslands(grid3)<<endl;


        Solution3 s3;
        vector<vector<char>>grid4={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
        cout<<s3.numIslands(grid4)<<endl;
        return 0;
    }
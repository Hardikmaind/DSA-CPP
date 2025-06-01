#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> res(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int>temp;
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++){
                        temp.push_back(grid[i+x][j+y]);
                    }
                }
                sort(temp.begin(),temp.end());
                int minDiff=INT_MAX;
                for(int z=1;z<temp.size();z++){
                    if(temp[z]!=temp[z-1]){

                        
                    minDiff=min(minDiff,abs(temp[z]-temp[z-1]));
                    }
                }
                res[i][j]=minDiff==INT_MAX?0:minDiff;
            }
        }
        return res;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 2;
    vector<vector<int>> result = obj.minAbsDiff(grid, k);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
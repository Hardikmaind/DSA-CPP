#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int orangesRotting(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            
            queue<pair<int, int>> q;
            int freshCount = 0;
    
            // Step 1: Count fresh oranges and push initial rotten oranges
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 2) {
                        q.push(make_pair(i, j));  // Push rotten orange coordinates
                    } else if (mat[i][j] == 1) {
                        freshCount++;  // Count fresh oranges
                    }
                }
            }
            
            if (freshCount == 0) return 0;  // No fresh oranges to rot
            
            int currTime = 0;
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // 4 directions
    
            // Step 2: BFS processing
            while (!q.empty() && freshCount > 0) {
                int size = q.size();
                currTime++;
    
                for (int i = 0; i < size; i++) {
                    pair<int, int> cell = q.front(); q.pop();
                    int x = cell.first, y = cell.second;
    
                    for (int d = 0; d < 4; d++) {
                        int nx = x + directions[d].first;
                        int ny = y + directions[d].second;
                        
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                            mat[nx][ny] = 2;  // Mark as rotten
                            freshCount--;  // Reduce fresh orange count
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
    
            return (freshCount == 0) ? currTime : -1;
        }
    };

    
    int main(){
        Solution obj;
        vector<vector<int>> mat = {{0,1,2},{0,1,2},{2,1,1}};
        cout<<obj.orangesRotting(mat)<<endl;

        return 0;
    }
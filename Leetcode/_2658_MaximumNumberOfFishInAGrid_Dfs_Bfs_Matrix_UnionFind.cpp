#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
class Solution {
private:
    // Function to perform BFS and count fishes in the connected component
    int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                    int row, int col) {
        int numRows = grid.size(), numCols = grid[0].size(), fishCount = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        // Directions for exploring up, down, left, right
        vector<int> rowDirections = {0, 0, 1, -1};
        vector<int> colDirections = {1, -1, 0, 0};

        // BFS traversal
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            fishCount += grid[row][col];

            // Exploring all four directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowDirections[i];
                int newCol = col + colDirections[i];
                if (0 <= newRow && newRow < numRows && 0 <= newCol &&
                    newCol < numCols && grid[newRow][newCol] &&
                    !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return fishCount;
    }

public:
    // Function to find the maximum number of fishes
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols));

        // Iterating through the entire grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    result = max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{0, 2, 1, 0},
                                {4, 0, 0, 3},
                                {1, 0, 0, 4},
                                {0, 3, 2, 0}};
    cout << obj.findMaxFish(grid) << endl;
    return 0;

}
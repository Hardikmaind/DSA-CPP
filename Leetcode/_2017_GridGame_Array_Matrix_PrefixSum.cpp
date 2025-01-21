#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/grid-game/solutions/6295086/grid-game
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    cout << sol.gridGame(grid) << endl;
    return 0;
}
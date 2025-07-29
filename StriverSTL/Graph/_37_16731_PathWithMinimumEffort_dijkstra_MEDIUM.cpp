#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;     
        pq.push({0, {0, 0}});
        diff[0][0] = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            // Early exit if we reach the bottom-right cell
            if (x == n - 1 && y == m - 1) return effort;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newEffort = max(abs(heights[x][y] - heights[nx][ny]), diff[x][y]);

                    if (newEffort < diff[nx][ny]) {
                        diff[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return diff[n - 1][m - 1];  // If while loop exits without early return
    }
};



int main(){
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl; // Output should be the minimum effort required to reach the bottom-right cell
    return 0;
}
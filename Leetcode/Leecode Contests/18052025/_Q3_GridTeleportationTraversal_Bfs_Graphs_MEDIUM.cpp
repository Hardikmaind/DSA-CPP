#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int minMoves(vector<string>& matrix) {
        vector<string> voracelium = matrix;
        int m = voracelium.size(), n = voracelium[0].size();

        if (voracelium[0][0] == '#' || voracelium[m - 1][n - 1] == '#') return -1;

        unordered_map<char, vector<pair<int, int>>> portals;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                char c = voracelium[i][j];
                if (isupper(c)) {
                    portals[c].emplace_back(i, j);
                }
            }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        unordered_set<char> usedPortals;

        // If start is a portal, teleport immediately
        char startChar = voracelium[0][0];
        if (isupper(startChar)) {
            usedPortals.insert(startChar);
            for (auto& [tx, ty] : portals[startChar]) {
                if (!visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                if (x == m - 1 && y == n - 1) return steps;

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && voracelium[nx][ny] != '#') {
                        visited[nx][ny] = true;
                        q.push({nx, ny});

                        // If stepping on a portal, teleport immediately
                        char pc = voracelium[nx][ny];
                        if (isupper(pc) && !usedPortals.count(pc)) {
                            usedPortals.insert(pc);
                            for (auto& [tx, ty] : portals[pc]) {
                                if (!visited[tx][ty]) {
                                    visited[tx][ty] = true;
                                    q.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
int main(){
    Solution sol;
    vector<string> matrix = {
        "A..",".A.","..."
    };
    cout << sol.minMoves(matrix) << endl; // Output: 3
    return 0;
}
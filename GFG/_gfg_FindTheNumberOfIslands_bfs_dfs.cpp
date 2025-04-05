#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m)
    {
        // Base cases
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 'W')
            return;

        grid[x][y] = 'W'; // Mark as visited

        // All 8 directions
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            dfs(grid, nx, ny, n, m);
        }
    }

    int countIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L')
                {
                    cnt++;
                    dfs(grid, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};


class Solution
{
public:
    int countIslands(vector<vector<char>> &grid)
    {
        // Code here
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 'W')
                    continue;

                queue<pair<int, int>> q;
                q.push({i, j});

                grid[i][j] = 'W';
                cnt += 1;

                while (!q.empty())
                {
                    auto f = q.front();
                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = f.first + dx[k];
                        int ny = f.second + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'L')
                        {
                            q.push({nx, ny});
                            grid[nx][ny] = 'W';
                        }
                    }
                }
            }
        }

        return cnt;
    }
};
int main()
{
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}

    };
    Solution sol;
    int result = sol.countIslands(grid);
    cout << "Number of islands (BFS): " << result << endl;

    Solution2 sol2;
    vector<vector<char>> grid2 = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}

    };
    int result2 = sol2.countIslands(grid2);
    cout << "Number of islands (DFS): " << result2 << endl;
    return 0;
}
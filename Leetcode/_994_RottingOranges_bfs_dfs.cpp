#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int freshorange = 0;
        int time = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshorange++;
                }
            }
        }
        if(freshorange == 0) return time;
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while (!q.empty() && freshorange > 0)
        {
            int size = q.size();
            time++;

            for (int i = 0; i < size; i++)
            {
                auto rotorange = q.front();
                q.pop();
                int x = rotorange.first;
                int y = rotorange.second;
                for (int i = 0; i < 4; i++)
                {
                    int deltaX = x + dx[i];
                    int deltaY = y + dy[i];
                    if (deltaX >= 0 && deltaX < grid.size() && deltaY >= 0 && deltaY < grid[0].size() && grid[deltaX][deltaY] == 1)
                    {
                        grid[deltaX][deltaY] = 2;
                        q.push({deltaX, deltaY});
                        freshorange--;
                    }
                }
            }
        }
        return (freshorange == 0) ? time : -1;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << obj.orangesRotting(grid) << endl;
    return 0;
}
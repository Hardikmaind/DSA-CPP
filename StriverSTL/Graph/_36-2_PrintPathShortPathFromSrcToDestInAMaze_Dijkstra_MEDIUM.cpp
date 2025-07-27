#include <bits/stdc++.h>
using namespace std;


//! no neet to use pririoty queue here, we can use normal queue since all weights are 1
class Solution
{
public:
    vector<pair<int,int>> shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return {{-1,-1}};

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, int>> q; //! here we can use the normal queue since all weights are 1. but incase different weights. we have to use the priority queueu

        vector<pair<int,int>>path;

        dist[source.first][source.second] = 0;
        q.push(source);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int x = q.top().first;
            int y = q.top().second;
            if (x == destination.first && y == destination.second){ //! here we are not calculating the whole dist array, we can stop when we reach the destination
                break;
            }
            q.pop();

            for (auto it : dirs)
            {
                int nx = x + it.first;
                int ny = y + it.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        if (dist[destination.first][destination.second] == 1e9){
            return {{-1,-1}};
        }
        int x = destination.first;
        int y = destination.second;
        while(x != source.first || y != source.second){
            path.push_back({x,y});
            for (auto it : dirs)
            {
                int nx = x + it.first;
                int ny = y + it.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && dist[nx][ny] == dist[x][y] - 1){
                    x = nx;
                    y = ny; 
                    break;
                }
            }
        }
        path.push_back({source.first, source.second});
        reverse(path.begin(), path.end());
        return path;
        
    }
};

int main()
{
    Solution sol;
 
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    auto result = sol.shortestPath(grid, source, destination); //! here we are not calculating the whole dist array, we can stop when we reach the destination
    for(auto &x:result){
        cout << x.first << " ";
        cout << x.second << " ";
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
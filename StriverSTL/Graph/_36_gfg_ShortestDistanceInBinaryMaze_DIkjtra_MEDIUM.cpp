#include <bits/stdc++.h>
using namespace std;

//! below soltion will give the TLE. it is not dijkstra's algorithm. it is a dfs based solution
class Solution2
{
public:
    void dfs(int i, int j, int wt, pair<int, int> &destination,
             vector<vector<int>> &grid, vector<vector<int>> &distMatrix,
             vector<vector<bool>> &vis, int n, int m)
    {

        // Base cases: out of bounds or visited or wall or not a shorter path
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1 || vis[i][j] || wt >= distMatrix[i][j])
            return;

        distMatrix[i][j] = wt;

        // If destination is reached, no need to go further
        if (i == destination.first && j == destination.second)
            return;

        vis[i][j] = true;

        // Manual directions: down, right, up, left
        dfs(i + 1, j, wt + 1, destination, grid, distMatrix, vis, n, m);
        dfs(i, j + 1, wt + 1, destination, grid, distMatrix, vis, n, m);
        dfs(i - 1, j, wt + 1, destination, grid, distMatrix, vis, n, m);
        dfs(i, j - 1, wt + 1, destination, grid, distMatrix, vis, n, m);

        vis[i][j] = false; // backtrack
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> distMatrix(n, vector<int>(m, 1e9));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(source.first, source.second, 0, destination, grid, distMatrix, vis, n, m);

        int res = distMatrix[destination.first][destination.second];
        return res == 1e9 ? -1 : res;
    }
};

//! below solution is a dijkstra's algorithm based solution. uses priority queue
class Solution4
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //! here we can use the normal queue since all weights are 1. but incase different weights. we have to use the priority queueu

        dist[source.first][source.second] = 0;
        q.push(source);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int x = q.top().first;
            int y = q.top().second;
            if (x == destination.first && y == destination.second){  //! here we are not calculating the whole dist array, we can stop when we reach the destination
                return dist[x][y];
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
                        /*
                         if (nx == destination.first && ny == destination.second){
                            return dist[nx][ny];
                        }
                        ⚠️ This can lead to an incorrect early return in some graphs (e.g., if multiple ways exist with smaller total distance).
                        ✅ You should still update all neighbors, and only return when the BFS naturally pops the destination (which will guarantee it's the shortest path) like I have above(checked after getting element out of the queue). */
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};

//! no neet to use pririoty queue here, we can use normal queue since all weights are 1
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q; //! here we can use the normal queue since all weights are 1. but incase different weights. we have to use the priority queueu

        dist[source.first][source.second] = 0;
        q.push(source);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            if (x == destination.first && y == destination.second)
            { //! here we are not calculating the whole dist array, we can stop when we reach the destination
                return dist[x][y];
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

        return -1;
    }
};

//! in below implementation of the djkstra algp. we are calculating the whole dist array which is not necessary for this problem. we can stop when we reach the destination
class Solution3
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q; //! here we can use the normal queue since all weights are 1. but incase different weights. we have to use the priority queueu

        dist[source.first][source.second] = 0;
        q.push(source);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
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

        //! after calculating whole dist array, we can check the distance to the destination. thought this is not necessary for this problem
        return dist[destination.first][destination.second] == 1e9 ? -1 : dist[destination.first][destination.second];
    }
};



//* BELOW IS STRIVERS CODE. PROPER PRIORITY QUEUE IMPLEMENTATION OF DIJKSTRA'S ALGORITHM.
class Solution5
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
                priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;     
 //! here we can use the normal queue since all weights are 1. but incase different weights. we have to use the priority queueu

        dist[source.first][source.second] = 0;
        pq.push({0,{source.first, source.second}});

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!pq.empty())
        {
            auto it = pq.top();
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();

            for (auto it : dirs)
            {
                int nx = x + it.first;
                int ny = y + it.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        pq.push({dist[nx][ny],{nx, ny}});
                    }
                }
            }
        }

        //! after calculating whole dist array, we can check the distance to the destination. thought this is not necessary for this problem
        return dist[destination.first][destination.second] == 1e9 ? -1 : dist[destination.first][destination.second];
    }
};

int main()
{
    Solution sol;
    Solution3 sol3;
    Solution4 sol4;
    Solution5 sol5;
    vector<vector<int>> grid = {
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 0, 1}};
    pair<int, int> source = {0, 0};
    pair<int, int> destination = {3, 3};

    int result = sol.shortestPath(grid, source, destination); //! here we are not calculating the whole dist array, we can stop when we reach the destination
    cout << "Shortest Path Length: " << result << endl;
    result = sol3.shortestPath(grid, source, destination); //! here we are calculating the whole dist array
    cout << "Shortest Path Length: " << result << endl;
    result = sol4.shortestPath(grid, source, destination); // here we are using the priority queue
    cout << "Shortest Path Length: " << result << endl;

    result = sol5.shortestPath(grid, source, destination); // here we are using the priority queue
    cout << "Shortest Path Length: " << result << endl;

    return 0;
}
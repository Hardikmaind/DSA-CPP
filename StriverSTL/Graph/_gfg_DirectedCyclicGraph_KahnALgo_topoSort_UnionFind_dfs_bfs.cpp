#include <bits/stdc++.h>
using namespace std;

//! Kahn’s Algorithm (BFS-style Topo Sort)
class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and indegree array
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);                            //! just this becasue it is an directed graph. if it was undirected then we would have added both u and v in the adjacency list. like adj[v].push_back(u); and adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Push all nodes with indegree 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If not all nodes were processed, cycle exists
        return count != V;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    int v = 4;
    cout << boolalpha << obj.isCyclic(v, edges) << endl;
}
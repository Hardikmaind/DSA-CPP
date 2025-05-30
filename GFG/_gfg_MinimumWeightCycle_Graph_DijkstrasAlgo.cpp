#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(int src, int des, unordered_map<int, vector<pair<int, int>>> &adj, int V)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(V, INT_MAX);
        pq.push({0, src});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &nbr : adj[u])
            {
                int v = nbr.first;
                int wt = nbr.second;
                if ((u == src && v == des) || (u == des && v == src))
                {
                    continue;
                }
                if (d + wt < res[v])
                {
                    res[v] = d + wt;
                    pq.push({d + wt, v});
                }
            }
        }
        return res[des];
    }
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int ans = INT_MAX;
        for (auto &edge : edges)
        {
            int path = dijkstra(edge[0], edge[1], adj, V);
            if (path != INT_MAX)
            {
                ans = min(ans, path + edge[2]);
            }
        }
        return ans;
    }
};


class Solution2 {
    public:
        int dijkstra(int src, int des, unordered_map<int, vector<pair<int, int>>>& adj,
                     int V, int skip_u, int skip_v) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<int> res(V, INT_MAX);
            res[src] = 0;
            pq.push({0, src});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                
                for (auto& [v, wt] : adj[u]) {
                    if ((u == skip_u && v == skip_v) || (u == skip_v && v == skip_u)) continue;
                    if (res[u] + wt < res[v]) {
                        res[v] = res[u] + wt;
                        pq.push({res[v], v});
                    }
                }
            }
            return res[des];
        }
    
        int findMinCycle(int V, vector<vector<int>>& edges) {
            unordered_map<int, vector<pair<int, int>>> adj;
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }
    
            int ans = INT_MAX;
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                int path = dijkstra(u, v, adj, V, u, v);
                if (path != INT_MAX) {
                    ans = min(ans, path + w);  // total cycle = path + skipped edge
                }
            }
    
            return ans == INT_MAX ? -1 : ans;
        }
    };
    

int main()
{
    Solution obj;
    Solution2 obj2;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 2, 2},
        {1, 3, 1},
        {1, 4, 1},
        {0, 4, 3},
        {2, 3, 4}};
    cout << obj.findMinCycle(V, edges);
    cout << endl;
    cout << obj2.findMinCycle(V, edges);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create adjacency list: {from -> [(to, weight)]}
        vector<vector<pair<int, int>>> adjlist(V);
        for (auto &x : edges) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adjlist[u].push_back({v, wt});
        }
        // Step 1: Topological Sort
        vector<int> topo = topoSortKahn(adjlist, V);
        // Step 2: Shortest path from source node
        int src = 0;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int node : topo) {
            if (dist[node] != INT_MAX) {
                for (auto& p : adjlist[node]) {
                    int v = p.first;
                    int wt = p.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        // Replace INT_MAX with -1 for unreachable nodes if required by the problem
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
    vector<int> topoSortKahn(const vector<vector<pair<int, int>>>& adjlist, int V) {
        vector<int> indegree(V, 0);
        // Calculate indegree of each node
        for (int u = 0; u < V; ++u) {
            for (auto& x : adjlist[u]) {
                int v = x.first;
                indegree[v]++;
            }
        }
        // Kahn's algorithm for topological sort
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (auto& p : adjlist[node]) {
                int v = p.first;
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return topo;
    }
};


int main(){
    Solution obj;
    vector<vector<int>> edges = {
        {0, 1, 2}, //! Edge from 0 to 1 with weight 2
        {0, 2, 1}, //! Edge from 0 to 2 with weight 4

    };
    int V = 4; // Number of vertices
    int E = edges.size(); // Number of edges
    vector<int> result = obj.shortestPath(V, E, edges);
    
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
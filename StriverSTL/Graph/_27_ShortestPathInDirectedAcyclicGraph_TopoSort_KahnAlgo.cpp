#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> topoSortKahn(const vector<vector<pair<int, int>>>& adjlist, int V) {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (const auto& [v, wt] : adjlist[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (const auto& [v, wt] : adjlist[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
    }

    vector<int> shortestPathInDAG(int V, int src, const vector<vector<pair<int, int>>>& adjlist) {
        vector<int> topo = topoSortKahn(adjlist, V);

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int node : topo) {
            if (dist[node] != INT_MAX) {
                for (const auto& [v, wt] : adjlist[node]) {
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution obj;
    vector<vector<pair<int, int>>> adjlist = {
        {{1, 2}},          // 0
        {{3, 1}},          // 1
        {{3, 3}},          // 2
        {},                // 3
        {{0, 3}, {2, 1}},  // 4
        {{4, 1}},          // 5
        {{4, 2}, {5, 3}}   // 6
    };

    int V = 7;
    int src = 6;
    vector<int> dist = obj.shortestPathInDAG(V, src, adjlist);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // Min-heap to store (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX); // Distance array initialized to infinity
        dist[src] = 0;
        pq.push({0, src}); // Push source with distance 0

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            // If we have already found a shorter path, skip processing
            if (d > dist[u]) continue;

            for (auto &neighbor : adj[u]) {
                int v = neighbor.first, weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main(){
     Solution s;
     int V=3;
     vector<vector<int>>edges={{0,1,1},{1,2,3},{0,2,6}};
     int src=2;
     auto res=s.dijkstra(V,edges,src);
     for(auto &x:res){
        cout<<x<<" ";
     }
}
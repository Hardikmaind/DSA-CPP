#include <bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adjlist(V);
        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjlist[u].push_back({v, wt});
        }
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //pq.push({src,0});       //first dist then node. or it will break dijkstra due to pririty queue.
        pq.push({0,src});  
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            if(node.first>dist[node.second]){
                continue;
            }
            for(auto &x:adjlist[node.second]){
                int v=x.first;
                int wt=x.second;
                if(dist[node.second]+wt<dist[v]){
                    dist[v]=dist[node.second]+wt;
                    pq.push({dist[node.second]+wt,v});
                }
            }
        }
        return dist;
    }
};

class Solution2 {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adjlist(V);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjlist[u].push_back({v, wt});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Priority queue: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int currDist = node.first;
            int u = node.second;

            if (currDist > dist[u]) continue;

            for (auto &x : adjlist[u]) {
                int v = x.first;
                int wt = x.second;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v}); // Push in correct order
                }
            }
        }

        return dist;
    }
};
int main(){
    // Example usage
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 1, 4},
        {2, 3, 8},
        {2, 4, 2},
        {3, 4, 7}
    };
    int src = 0;
    vector<int> result = sol.dijkstra(V, edges, src);
    
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    Solution2 sol2;
    vector<int> result2 = sol2.dijkstra(V, edges, src);
    for (int dist : result2) {
        cout << dist << " ";
    }
    cout << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          // Code here
          const int INF = 1e8; // 100000000
          vector<int> dist(V, INF);
          dist[src] = 0;
          // Step 1: Relax all edges V-1 times
          for (int i = 0; i < V - 1; i++) {
              for (int j = 0; j < edges.size(); j++) {
                  int u = edges[j][0];
                  int v = edges[j][1];
                  int w = edges[j][2];
      
                  if (dist[u] != INF && dist[u] + w < dist[v]) {
                      dist[v] = dist[u] + w;
                  }
              }
          }
          // Step 2: Check for negative weight cycle
          for (int j = 0; j < edges.size(); j++) {
              int u = edges[j][0];
              int v = edges[j][1];
              int w = edges[j][2];
      
              if (dist[u] != INF && dist[u] + w < dist[v]) {
                  // Negative cycle detected
                  return {-1};
              }
          }
          // Step 3: Replace INF with 1e8 for unreachable vertices
          for (int i = 0; i < V; i++) {
              if (dist[i] == INF) dist[i] = 1e8;
          }
          return dist;
              
      }
  };

  
  int main(){
      int V = 5;
      vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
      int src = 0;
      Solution obj;
      vector<int> res = obj.bellmanFord(V, edges, src);
      for (int i = 0; i < V; i++) {
          cout << res[i] << " ";
      }
  }
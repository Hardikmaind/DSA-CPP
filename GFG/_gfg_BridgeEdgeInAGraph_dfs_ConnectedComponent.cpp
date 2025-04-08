#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int c, int d) {
          vis[node] = 1;
          for (int neighbor : adj[node]) {
              // Skip the edge (c, d) or (d, c)
              if (!vis[neighbor] && !((node == c && neighbor == d) || (node == d && neighbor == c))) {
                  dfs(neighbor, adj, vis, c, d);
              }
          }
      }
      
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Convert edge list to adjacency list
          vector<vector<int>> adj(V);
          for (auto &edge : edges) {
              int u = edge[0], v = edge[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
      
          vector<int> vis(V, 0);
      
          // Start DFS from vertex c, skipping the edge (c, d)
          dfs(c, adj, vis, c, d);
      
          // If d is not visited, (c, d) was a bridge
          return !vis[d];
      }
  };

  int main(){
    Solution s;
    vector<vector<int>> edges={{0,1},{1,2},{2,3}};
    int V=4;
    int c=1,d=2;
    cout<<s.isBridge(V,edges,c,d)<<endl;
    return 0;
  }
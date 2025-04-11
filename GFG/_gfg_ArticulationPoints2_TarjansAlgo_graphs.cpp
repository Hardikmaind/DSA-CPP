#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
       void dfs(int u, int parent, vector<int> adj[], vector<bool>& vis,vector<int>& tin, vector<int>& low, vector<bool>& isArticulation, int& timer) {
          vis[u] = true;
          tin[u] = low[u] = timer++;
          int children = 0;
          for (int v : adj[u]) {
              if (v == parent) continue;
              if (!vis[v]) {
                  dfs(v, u, adj, vis, tin, low, isArticulation, timer);
                  low[u] = min(low[u], low[v]);
                  // Non-root case
                  if (low[v] >= tin[u] && parent != -1)
                      isArticulation[u] = true;
                  ++children;
              } else {
                  low[u] = min(low[u], tin[v]);  // back edge
              }
          }
          // Root case
          if (parent == -1 && children > 1)
              isArticulation[u] = true;
      }
      vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
          vector<int> adj[V];
          for (auto& e : edges) {
              adj[e[0]].push_back(e[1]);                    //! instead of doing int u=e[0] and int v=e[1] i have done it directly
              adj[e[1]].push_back(e[0]);
          }
          vector<bool> vis(V, false), isArticulation(V, false);
          vector<int> tin(V, -1), low(V, -1);
          int timer = 0;
          for (int i = 0; i < V; ++i) {
              if (!vis[i]) {
                  dfs(i, -1, adj, vis, tin, low, isArticulation, timer);
              }
          }
          vector<int> res;
          for (int i = 0; i < V; ++i) {
              if (isArticulation[i]) res.push_back(i);
          }
          if (res.empty()) return {-1};
          return res;
      }
  };

  int main(){
    Solution s;
    vector<vector<int>>edges={{0,1},{1,4},{4,3},{4,2},{2,3}};
    int V=5;
    auto res=s.articulationPoints(V,edges);
    for(auto &x :res){
        cout<<x<<" ";
    }
    return 0;
  }
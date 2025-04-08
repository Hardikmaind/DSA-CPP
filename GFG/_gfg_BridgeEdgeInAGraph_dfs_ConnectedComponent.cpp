#include <bits/stdc++.h>
using namespace std;


//! tc : O(V+E) and sc : O(V)
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


  //! tc : O(V+E) and sc : O(V)
 class Solution2{
    public:
        void dfs2(int c,vector<int>& vis,vector<vector<int>>&adj){
            vis[c]=1;
            for(auto x:adj[c]){
                if(!vis[x]){
                    dfs2(x,vis,adj);
                }
            }
        }
        bool isBridge2(int V, vector<vector<int>>& edges, int c, int d) {
            
            vector<vector<int>>adj(V);
            for(auto &x:edges){
                if (!((x[0] == c && x[1] == d) || (x[0] == d && x[1] == c))){           //! here we didnt add the edge C to D

                    adj[x[0]].push_back(x[1]);
                    adj[x[1]].push_back(x[0]);
                }
            }
            int count=0;
            vector<int>vis(V,false);
            dfs2(c,vis,adj);
            return !vis[d];

 }
};

  int main(){
    Solution s;
    vector<vector<int>> edges={{0,1},{1,2},{2,3}};
    int V=4;
    int c=1,d=2;
    cout<<boolalpha<<s.isBridge(V,edges,c,d)<<endl;
    
    Solution2 s2;
    vector<vector<int>> edges2={{0,1},{1,2},{2,3}};
    int V2=4;
    int c2=1,d2=2;
    cout<<"HEllo world"<<endl;
    cout<<boolalpha<<s2.isBridge2(V2,edges2,c2,d2)<<endl;

    return 0;
  }
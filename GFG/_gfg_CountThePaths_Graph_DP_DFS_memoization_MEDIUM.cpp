#include <bits/stdc++.h>
using namespace std;

//! THIS BELOW IS THE BRUTE FORCE DFS APPROACH. TC IS O(V^V) AND SC IS O(V).
class Solution2 {
  public:
  void dfs(vector<vector<int>>& adjlist, int src, int dest, vector<int>& vis, int &pathCount) {
      if(src == dest) {
          pathCount++;
          return;
      }

      vis[src] = 1;
      for(auto &x : adjlist[src]) {
          if(!vis[x]){
              dfs(adjlist, x, dest, vis, pathCount);
          }
      }
      vis[src] = 0;
  }

  int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
      vector<int> vis(V, 0);
      vector<vector<int>> adjlist(V);

      for(auto &x : edges) {
          adjlist[x[0]].push_back(x[1]);
      }

      int pathCount = 0;
      dfs(adjlist, src, dest, vis, pathCount);

      return pathCount;
  }
};

//! THIS BELOW IS OPTIMIZED DFS WITH MEMOIZATION. TC IS O(V + E) AND SC IS O(V).
class Solution {
  public:
  int dfs(vector<vector<int>>& adjlist, int src, int dest, vector<int>& dp, vector<bool>& visited) {
      if (src == dest) return 1;
      if (dp[src] != -1) return dp[src];

      visited[src] = true;
      int count = 0;
      for (int neighbor : adjlist[src]) {
          if (!visited[neighbor]) {
              count += dfs(adjlist, neighbor, dest, dp, visited);
          }
      }
      visited[src] = false;

      return dp[src] = count;
  }

  int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
      vector<vector<int>> adjlist(V);
      for (auto &x : edges) {
          adjlist[x[0]].push_back(x[1]);
      }

      vector<int> dp(V, -1);           // Memoization: dp[i] = number of paths from i to dest
      vector<bool> visited(V, false);  // To avoid cycles if the graph isn't a DAG

      return dfs(adjlist, src, dest, dp, visited);
  }
};


int main(){
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int src = 0, dest = 4;

    Solution sol;
    int result = sol.countPaths(edges, V, src, dest);
    cout << "Number of paths from " << src << " to " << dest << ": " << result << endl;

    Solution2 sol2;
    int result2 = sol2.countPaths(edges, V, src, dest);
    cout << "Number of paths from " << src << " to " << dest << " (Brute Force): " << result2 << endl;

    return 0;
}
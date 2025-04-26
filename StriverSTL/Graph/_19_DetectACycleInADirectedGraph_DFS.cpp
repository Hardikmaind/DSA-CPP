#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool dfs(int start, vector<int>& vis, vector<int>& path, vector<vector<int>>& adjlist) {
            vis[start] = 1;
            path[start] = 1;
            for (auto& x : adjlist[start]) {
                if (!vis[x]) {
                    if (dfs(x, vis, path, adjlist)) {
                        return true; // cycle found
                    }
                } else if (path[x]) {
                    return true; // back edge found, cycle exists
                }
            }
            path[start] = 0; // backtrack
            return false; // no cycle from this path
        }
    public:
        bool isCyclic(int V, vector<vector<int>>& edges) {
            vector<int> vis(V, 0);
            vector<int> path(V, 0);
            vector<vector<int>> adjlist(V);
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adjlist[u].push_back(v);
            }
            for (int i = 0; i < V; ++i) {
                if (!vis[i]) {
                    if (dfs(i, vis, path, adjlist)) return true;
                }
            }
            return false; // no cycles in any component
        }
    };

    
    int main(){
        Solution obj;
        int V = 4;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0},{2,3}};
        cout << (obj.isCyclic(V, edges) ? "Cycle detected" : "No cycle detected") << endl;    
    }
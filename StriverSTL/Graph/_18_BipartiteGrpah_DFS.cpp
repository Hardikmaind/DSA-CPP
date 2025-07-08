#include <bits/stdc++.h>
using namespace std;



class Solution2 {
private:
    bool dfs(int src,vector<int>&vis,vector<vector<int>>&adjlist){
        if(!vis[src]){         //! it is better to handle this in the main function only. like in below code.
            vis[src]=1;
        }
        for(auto&x:adjlist[src]){
            if(!vis[x]){
                vis[x]=vis[src]==1?-1:1;
                if(!dfs(x,vis,adjlist)){
                    return false;
                }
            }
            else if(vis[src]==vis[x]){      //if visited and color of src(x is src) and parent(src will be the parent) is the same then return false;
             return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {          //given is adjlist
        int V=graph.size();
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(!dfs(i,vis,graph)){
                    return false;
                }
            }
        }
        return true;
        
    }
};


//! this is the best code. tc is O(V+E) and sc is O(V). 
class Solution {
    private:
        bool dfs(int src, vector<int>& vis, vector<vector<int>>& adjlist) {
            for (auto& x : adjlist[src]) {
                if (!vis[x]) {
                    vis[x] = -vis[src];  // Assign opposite color
                    if (!dfs(x, vis, adjlist)) return false;
                } else if (vis[x] == vis[src]) {
                    return false; // Conflict in coloring
                }
            }
            return true;
        }
    
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int V = graph.size();
            vector<int> vis(V, 0); // 0: unvisited, 1: color1, -1: color2
            for (int i = 0; i < V; ++i) {
                if (!vis[i]) {
                    vis[i] = 1; // Assign initial color
                    if (!dfs(i, vis, graph)) return false;
                }
            }
            return true;
        }
    };

    

    int main(){
        Solution obj;
        vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}}; // Example graph
        cout << boolalpha << obj.isBipartite(graph) << endl; // Output: true


        Solution2 obj2;
        vector<vector<int>> graph2 = {{1,2,3},{0,2},{0,1,3},{0,2}}; // Example graph
        cout << boolalpha << obj2.isBipartite(graph2) << endl; // Output: false
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
 
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        // Initialize distances
        vector<int> dist(V, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // Not visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
        
        
    }
};


//! no topo sort require since it is UNDIRECTED graph and all edges have unit weight
class Solution2{
    public:
        vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        vector<int> dist(V, INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

           if(dist[node]!=INT_MAX){
                for(auto x:adj[node]){
                    if(dist[node]+1<dist[x]){
                        dist[x] = dist[node] + 1;
                        q.push(x);
                    }
                }
           }
        }
        vector<int>res(V,-1);
        for(int i=0;i<V;i++){
            if(dist[i]!=INT_MAX){
                res[i] = dist[i];
            }else{
                res[i] = -1; // If node is unreachable, set distance to -1
            }
        }

        return res;
        
        
    }
};

int main(){
    // Example usage
    Solution sol;
    vector<vector<int>> adj = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 3},     // Node 1 is connected to nodes 0 and 3
        {0, 4},     // Node 2 is connected to nodes 0 and 4
        {1},        // Node 3 is connected to node 1
        {2}         // Node 4 is connected to node 2
    };
    int src = 0; // Starting from node 0
    vector<int> result = sol.shortestPath(adj, src);
    
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    Solution2 sol2;

     vector<int> result2 = sol2.shortestPath(adj, src);
    
    for (int dist : result2) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
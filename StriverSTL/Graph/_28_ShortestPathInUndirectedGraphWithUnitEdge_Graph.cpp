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

           if(dist[node]!=INT_MAX){                                     //! The node you're processing was pushed into the queue only after its distance was set, like this. SO it is unnecessary to check dist[node] != INT_MAX
                for(auto x:adj[node]){
                    if(dist[node]+1<dist[x]){                   //? +1 because its a unit edge
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
/*
🔍 Changes and Optimizations:
Original	                                               Optimized
Used INT_MAX as default                 	            Use -1 directly to mean "unreachable", simplifies logic
Checked if(dist[node] != INT_MAX) in loop	            No need; node is always visited
Used extra res vector	                                Reused dist directly for return value
Condition if(dist[node]+1<dist[x])                  	In BFS on unweighted graph, if dist[x] == -1 is enough

✅ Why This is Correct:
You only ever update a node's distance once, when it's first discovered.
BFS ensures the first time you reach a node is the shortest path.
Avoids unnecessary comparisons like dist[node] + 1 < dist[x].
*/

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
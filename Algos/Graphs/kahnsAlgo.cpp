#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> topoSort(int V, vector<int> adj[]) {
            vector<int> indegree(V, 0);
            
            // Step 1: Calculate the indegree for each vertex
            for(int i = 0; i < V; i++) {
                for(auto &x : adj[i]) {
                    indegree[x]++;
                }
            }
            
            queue<int> q;
            
            // Step 2: Push vertices with 0 indegree into the queue
            for(int i = 0; i < V; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            vector<int> toposort;
    
            // Step 3: Perform BFS and generate the topological order
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                toposort.push_back(node);
    
                // Decrease indegree of adjacent nodes
                for(auto &x : adj[node]) {
                    indegree[x]--;
                    if(indegree[x] == 0) {
                        q.push(x);
                    }
                }
            }
    
            return toposort;
        }
    };

    

    int main(){
        Solution obj;
        vector<vector<int>> edge={{0,1},{0,2},{1,2},{2,3}};
        int V=4;
        vector<int> adj[V];
        for(auto &x:edge){
            adj[x[0]].push_back(x[1]);
        }
        auto res=obj.topoSort(V,adj);
        cout<<"The topological sort of the graph is: "<<endl;
        for(auto &x:res){
            cout<<x<<" ";
        }
        cout<<endl;
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;

//! there are two ways to detect cycle in a directed graph
//! 1. using dfs and visited array
//! 2. using dfs and recursion stack
//! 3. using kahn's algorithm (topological sort) and indegree array . check if the number of nodes in the topological sort is equal to the number of nodes in the graph. if not then there is a cycle in the graph. you can save the space by simply counting the number of nodes in the topological sort and comparing it with the number of nodes in the graph. if they are not equal then there is a cycle in the graph.



// THIS IS THE METHOD 2. OF KAHNS ALGO(topo sort). TC IS\

// Space Optimization:
// In this particular algorithm, we are only concerned about the length of the topological sorting and not the exact nodes it contains. So in step 3, after popping a node out of the queue, instead of putting it into an array we can carry a counter variable and increment it. After completing the BFS this counter variable will give the length of the topological sorting. So, we need not use the extra answer.

 
class Solution{
    public:
        bool kahn_topoSort_algo(int V,vector<vector<int>> &edge){
            vector<vector<int>> adjlist(V);
            vector<int>indegree(V);
            for(auto &x:edge){
                adjlist[x[0]].push_back(x[1]);
                indegree[x[1]]++;
            }
            queue<int>q;
            for(auto &x:indegree){
                if(x==0){
                    q.push(x);
                }
            }
            int count=0;        //! taking the count variable instead of the toposort vector. since we dont have to return the toposorted vector
            while(!q.empty()){
                int node=q.front();
                q.pop();
                count++;            //! used the counter instead of the toposorted vector, since here we dont need to find the toposorted vector.
                for(auto x:adjlist[node]){

                    indegree[x]--;      //reduce the indegree
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }
            }
            return count==V?false:true;         // we can also return directly count!=V; but this is more readable.

            return true;
        }
};


//! this is a solution using dfs and vis and path array. 
class Solution2 {
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
    vector<vector<int>> edge={{0,1},{0,2},{1,2},{2,3}};
    int V=4;
    cout<<boolalpha<<obj.kahn_topoSort_algo(V,edge);
    return 0;
}
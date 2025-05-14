#include<bits/stdc++.h>
using namespace std;





class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        //here i have created the adjlist from the graph. and reversed the edges.
        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {           //! isolated nodes will be pushed to the queue here. since they have the indegree 0;
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;          //just to return it in ascending order we are doing this.
            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        vector<int> safeNodes;          //! used this becuase want to return the array in ascending order, so we will iterate fromn 0 to n and whenever there is check , we will push back
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


int main(){
    Solution obj;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};        //! 6th node is isolated node. so it will be there
    vector<int> result = obj.eventualSafeNodes(graph);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
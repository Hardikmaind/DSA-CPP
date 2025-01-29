#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/redundant-connection/solutions/6322474/redundant-connection

class Solution {
private:
    // Performs DFS and returns true if there's a path between src and target.
    bool isConnected(int src, int target, vector<bool>& visited,
                     vector<int> adjList[]) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        int isFound = false;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for (auto edge : edges) {
            vector<bool> visited(N, false);

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};
 int main(){
    Solution sol;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> res = sol.findRedundantConnection(edges);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
 }
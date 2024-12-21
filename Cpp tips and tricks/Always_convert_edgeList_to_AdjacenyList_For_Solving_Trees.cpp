#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>  convertToAdjacencyList(int n, vector<vector<int>> &edges) {
        // Step 1: Create adjacency list from edges
        // vector<int> adjList[n];
            vector<vector<int>> adjacencyList(n);

        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        //return adjList;        //Returning vector<int> adjList[n] directly from a C++ function isn't possible.  
        return adjacencyList;
       
    }
};
int main(){
    vector<vector<int>>edges={{0,2},{1,2},{1,3},{2,4}};
    int n=5;        //n=>Number of vertices=>0,1,2,3,4. total 5 are there

    Solution* solution = new Solution();
    auto res = solution->convertToAdjacencyList(n, edges);
    // Print the adjacency list
    for (int i = 0; i < res.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int j : res[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

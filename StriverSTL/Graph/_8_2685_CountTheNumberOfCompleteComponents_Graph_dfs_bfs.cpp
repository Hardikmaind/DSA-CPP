#include <bits/stdc++.h>
using namespace std;

/*You're not checking whether a connected component is a complete graph.

A complete graph means:

Every pair of distinct vertices is connected by a unique edge.

In an undirected complete graph with k nodes, the number of edges should be exactly k * (k - 1) / 2.*/




class Solution {
    private:
    void dfs(int src, vector<vector<int>>& adjlist, vector<int>& vis, int& nodeCount, int& edgeCount) {
        vis[src] = 1;
        nodeCount++;
        edgeCount += adjlist[src].size();  // Each edge will be counted twice
        for (auto& node : adjlist[src]) {
            if (!vis[node]) {
                dfs(node, adjlist, vis, nodeCount, edgeCount);
            }
        }
        }
        public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adjlist(n);
            for (auto& x : edges) {
                adjlist[x[0]].push_back(x[1]);
                adjlist[x[1]].push_back(x[0]);
            }
            int count = 0;
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int nodeCount = 0;
                    int edgeCount = 0;
                    dfs(i, adjlist, vis, nodeCount, edgeCount);
                    // edgeCount is doubled due to undirected edges
                    if (edgeCount / 2 == nodeCount * (nodeCount - 1) / 2) {         //since 2E=n*(n-1)/2;
                        count++; // it's a complete graph
                    }
                }
            }
            return count;
        }
    };
    
    int main(){
        Solution s;
        vector<vector<int>>edgelist={{0,1},{0,2},{1,2},{3,4}};
        int n=6;
        auto res=s.countCompleteComponents(n,edgelist);
        cout<<res<<endl;


        vector<vector<int>>edgelist2={{0,1},{0,2},{1,2},{3,4},{3,5}};
        int n2=6;
        auto res2=s.countCompleteComponents(n2,edgelist2);      //! here the ans is 1 because the graph is not complete( means every pair of distinct vertices is not connected by a unique edge.(condition for the complete graph)).
        cout<<res2<<endl;
        return 0;
    }
    
    
    // class Solution {
    //     private:
    //         void dfs(int src, vector<vector<int>>& adjlist,vector<int>&vis){
    //             vis[src]=1;
    //             for(auto& node:adjlist[src]){
    //                 if(!vis[node]){
    //                     dfs(node,adjlist,vis);
    //                 }
    //             }
    
    //         }
    // public:
    //     int countCompleteComponents(int n, vector<vector<int>>& edges) {
    //         vector<vector<int>>adjlist(n);
    
    //         for(auto &x:edges){
    //             adjlist[x[0]].push_back(x[1]);
    //             adjlist[x[1]].push_back(x[0]);
    //         }
    //         int count=0;
    //         vector<int>vis(n,0);
    //         for(int i=0;i<n;i++){
    //             if(!vis[i]){
    //                 count++;
    //                 dfs(i,adjlist,vis);
    //             }
    //         }
    //         return count;
    //     }
    // };
    
    
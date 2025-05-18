#include <bits/stdc++.h>
using namespace std;

//! below is a dfs solution
class Solution
{
public:
    void dfs(int src, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[src] = 1;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[src][i] && !vis[i])
            {
                dfs(i, vis, adj);
            }
        }

        /*
        ! above loop can be replaced with below loop
        for(auto x:adj[src]){
            if(!vis[x]){
                dfs(x, vis, adj);
            }
        }
        */
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int noOfProvince = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {

                noOfProvince++;
                dfs(i, vis, adj);
            }
        }
        return noOfProvince;
    }
};

//! this below is a bfs solution

class Solution2{
    public:
    void bfs2(int src, vector<int>& vis, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adj.size(); i++) {          //! bfs can also be done by such loop
                if (adj[node][i] && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    void bfs(int src,vector<int>&vis,vector<vector<int>>&adjlist){
        vis[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node =q.front();q.pop();
            for(auto &x:adjlist[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int noOfProvince = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)         //iterate over all componenets
        {
            if (!vis[i])
            {

                noOfProvince++;
                bfs(i, vis, adj);
            }
        }
        return noOfProvince;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int V = 3;
    int result = obj.numProvinces(adj, V);
    cout << result << endl;

    Solution2 obj2;
    int result2 = obj2.numProvinces(adj, V);
    cout << result2 << endl;
    return 0;
}
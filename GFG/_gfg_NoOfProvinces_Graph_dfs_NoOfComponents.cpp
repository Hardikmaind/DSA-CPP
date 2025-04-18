#include <bits/stdc++.h>
using namespace std;

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
class Solution2
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

int main()
{
    Solution obj;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int V = 3;
    int result = obj.numProvinces(adj, V);
    cout << result << endl;
    return 0;
}
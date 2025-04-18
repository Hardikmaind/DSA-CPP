#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsUtil(int i, vector<vector<int>> &adjlist, vector<bool> &vis, vector<int> &comp)
    {
        vis[i] = true;
        comp.push_back(i);
        for (auto x : adjlist[i])
        {
            if (!vis[x])
            {
                dfsUtil(x, adjlist, vis, comp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adjlist(V);
        for (auto &pair : edges)
        {
            adjlist[pair[0]].push_back(pair[1]);
            adjlist[pair[1]].push_back(pair[0]);
        }
        vector<vector<int>> res;
        vector<bool> vis(V, false); // to optimize more use sets.
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                vector<int> comp;
                dfsUtil(i, adjlist, vis, comp);
                res.push_back(comp);
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {2, 1},

        {3, 4},

    };
}
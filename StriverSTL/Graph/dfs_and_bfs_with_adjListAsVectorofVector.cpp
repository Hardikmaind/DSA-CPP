#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfsutil(int start, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res){
        res.push_back(start);
        vis[start] = 1;
        for (auto x : adj[start])
        {
            if (vis[x] != 1)
            {
                dfsutil(x, adj, vis, res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj){
        // Code here
        int n = adj.size();

        vector<int> vis(n, 0), res;
        dfsutil(0, adj, vis, res);
        return res;
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        int n=adj.size();
        vector<int>vis(n,0),res;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto x:adj[node]){
                if(vis[x]!=1){
                    q.push(x);
                    vis[x]=1;
                }
            }
            
        }
        return res;
        
    }
};

int main()
{
    vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
    //! Why is this allowed?
    //! In C++, calling a non-static method requires an instance of the class. Since you are creating a temporary instance (Solution()), the function call is valid.

    vector<int> res=Solution().dfs(adj);        // here Solution() is a temporary object..like we do in java "new Solution()"
    cout<<"DFS: ";
    for(auto x:res)
    {
        cout<<x<<" ";
    }

    // if the dfs method was the static method, then we would do below
    // vector<int> res1=Solution::dfs(adj);




    //* THIS IS BFS CODE
    res.clear();
    cout<<"\nBFS: ";
    res=Solution().bfs(adj);
    for(auto x:res)
    {
        cout<<x<<" ";
    }
    return 0;

}
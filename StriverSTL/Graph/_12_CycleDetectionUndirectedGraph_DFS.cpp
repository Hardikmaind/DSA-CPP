#include <bits/stdc++.h>
using namespace std;


/*🔥 Quick Answer:
Because dfs(...) returns a value (a bool), and that value tells you whether a cycle has been detected during that recursive call.

If you just write:
dfs(x, src, adjlist, vis);

Then even if the recursive DFS found a cycle, you're ignoring the result — so your program won’t respond to it, and will continue checking other neighbors as if nothing happened.

💡 Think of it like this:
Imagine dfs is a messenger who comes back with a note saying “Cycle found!” –
if you don't read the note (i.e., don’t check the return value), you’ll never know that a cycle exists. */
class Solution {
    private:
       bool dfs(int src,int parent ,vector<vector<int>>&adjlist,vector<int>&vis){
        vis[src]=1;
        for(auto&x:adjlist[src]){
            if(!vis[x]){
                //* src will become the parent the next time we do it again
                 if (dfs(x, src, adjlist, vis)) return true;        //! this is imp see the above comment
            }else if(vis[x] && x!=parent){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V, 0);
        vector<vector<int>> adjlist(V);
        
        for (int i = 0; i < edges.size(); i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < V; i++) {       //! this is req , if the graph is not connected
            if (!vis[i]) {
                if (dfs(i,-1, adjlist, vis)) return true;
            }
        }
        return false;

        
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges={{0,1},{0,2},{1,2},{2,3}};
    int n=4;
    cout << boolalpha << obj.isCycle(n,edges);
    return 0;

}
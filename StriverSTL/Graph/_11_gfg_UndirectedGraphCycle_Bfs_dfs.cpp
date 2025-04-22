#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
        bool detectCycle(int src,vector<vector<int>>& adjlist,vector<int>&vis){
            queue<pair<int,int>>q;
            vis[src]=1;
            q.push({src,-1});
            while(!q.empty()){
                int parent=q.front().second;
                int node=q.front().first;
                q.pop();
                for(auto x:adjlist[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push({x,node});
                    }else if(vis[x] && x!=parent){
                        return true;
                    }
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
                if (detectCycle(i, adjlist, vis)) return true;
            }
        }
        return false;

        
    }
};


int main(){
    Solution obj;
    vector<vector<int>> edges={{0,1},{0,2},{1,2},{2,3}};
    int n=4;
    bool ans=obj.isCycle(n,edges);
    cout<<boolalpha<<ans<<endl;
    return 0;
}
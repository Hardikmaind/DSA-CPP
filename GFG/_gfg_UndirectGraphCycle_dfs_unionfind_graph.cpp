#include <bits/stdc++.h>
using namespace std;


class Solution {
    public :
        bool detect(vector<vector<int>>&adj, vector<int>&vis, int node){
                vis[node]=1;
                queue<pair<int,int>> q;
                q.push({node,-1});
                
                while(!q.empty()){
                    int src=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    
                    for(auto adjacentNode:adj[src]){
                        if(!vis[adjacentNode]){
                            vis[adjacentNode]=1;
                            q.push({adjacentNode,src});
                        }
                        else if( parent != adjacentNode){
                            return true;
                        }
                        
                    }
                    
                }
                return false;
            }
            bool isCycle(int V, vector<vector<int>>&adj) {
                // Code here
                vector<int>vis(V,0);
                for(int i=0;i<V;i++){
                    if(!vis[i]){
                        if(detect(adj,vis,i)) return true;
                    }
                }
                return false;
            }
};


int main(){
    Solution s;
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {0, 1};
    adj[1] = {0, 2};
    adj[2] = {1, 2};
    adj[3] = {2, 3};
    

    bool result = s.isCycle(V, adj);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}
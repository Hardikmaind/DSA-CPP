#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          vector<int> in(V,0);
         
         vector<int> adj[V];
         vector<int> res;
         
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it : adj[node]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        
        
        for(int i=0;i<V;i++){
            if(in[i]>0) res.push_back(i);
        }
        
        
        return res;
      }
  };

  int main(){
    Solution obj;
    int v=4;
    vector<vector<int>>edges={{3,0},{1,0},{2,0}};
    vector<int>res=obj.topoSort(v,edges);
    for(auto x: res){
        cout<<x<<endl;
    }
  }
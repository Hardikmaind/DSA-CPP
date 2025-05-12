#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(int src,vector<vector<int>>&adjlist,vector<int>&vis,stack<int>&stack){
            vis[src]=1;
            for(auto &x :adjlist[src]){
                if(!vis[x]){
                    dfs(x,adjlist,vis,stack);
                }
            }
            stack.push(src);
            
            
        }
        vector<int> topoSortDFS(vector<vector<int>> &edges,int V){
             vector<vector<int>> adjlist(V);
            for(auto &x:edges){
                adjlist[x[0]].push_back(x[1]);
            }
        
            vector<int>res;
            vector<int>vis(V,0);
            stack<int>stack;
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    dfs(i,adjlist,vis,stack);
                }
            }

            while(!stack.empty()){
                res.push_back(stack.top());stack.pop();
                
            }
            return res;

    
        }
};


//! TOPO SORT VIA KAHNS ALGO
class Solution2 {
  public:
  void kahnsAlgo(vector<vector<int>>&adjlist,vector<int>&topoSorted,int V){
            
            queue<int>q;
            vector<int>indegree(V,0);
            for(auto &x:adjlist){
                for(auto &y:x){
                    indegree[y]++;
                }
            }
            
            for(int i=0;i<V;i++){
                if(!indegree[i]){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int node=q.front();q.pop();
                topoSorted.push_back(node);
                for(auto &x:adjlist[node]){
                    indegree[x]--;
                    if(!indegree[x]){
                        q.push(x);
                    }
                }
            }
            
            
            
        }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(V);
            for(auto &x:edges){
                adjlist[x[0]].push_back(x[1]);
            }
        
            vector<int>topoSorted;
            kahnsAlgo(adjlist,topoSorted,V);
            
            return topoSorted;

    }
};

int main(){
    vector<vector<int>> edges={{5,0},{5,2},{2,3},{3,1},{4,0},{4,1}};
    int V=6;
    Solution obj;
    auto res=obj.topoSortDFS(edges,V);
    for(auto&x:res){
        cout<<x<<" ";
    }
    cout<<endl;

    Solution2 obj2;
    auto res2=obj2.topoSort(V,edges);
    cout<<endl;
    for(auto&x:res2){
        cout<<x<<" ";
    }

   
    
    return 0;
}


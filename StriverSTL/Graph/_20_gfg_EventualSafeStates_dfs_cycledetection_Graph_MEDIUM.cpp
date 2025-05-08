#include <bits/stdc++.h>
using namespace std;

//! any node that is part of cycle or any node that direct to a node which has a path to a cycle is not an eventual safe node else all are safe node

class Solution {
    public:
    
    //* here of returning just bool. i can backtrack also
      bool dfs(int src,vector<int>&vis,vector<int>&path,vector<int>&check,vector<int>adj[]){
          vis[src]=1;
          path[src]=1;
          for(auto &x:adj[src]){
              if(!vis[x]){
                  if(dfs(x,vis,path,check,adj)){
                      check[x]=0;             //*here no need to write this. just for understanding i am writing this
                      return true;
                  }
              }else if(vis[x] && path[x]){
                  check[x]=0;    //*here no need to write this. just for understanding i am writing this
                  return true;
              }
          }
          
          //*if dfs complete without cycle(without going and breaking(means returning) inside the above function then it means there is cycle) .
          check[src]=1;
          path[src]=0;        //*here we backtrack;
          return false;
      }
      vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
          // code here
          //these below two array for checking the cycle via dfs
          vector<int>vis(V,0);
          vector<int>path(V,0);
  
          vector<int>check(V,0);
          for(int i=0;i<V;i++){
              if(!vis[i]){
                  dfs(i,vis,path,check,adj);          //*just a small change ,here i dont have to break. go through whole dfs
              }
          }
          vector<int>res;
          for(int i=0;i<V;i++){
              if(check[i]==1){
                  res.push_back(i);
              }
          }
          return res;
          
      }
  };
  
// // Online C++ compiler to run C++ program online
#include <iostream>
#include <thread>
#include <vector>
#include <stack>
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
int main(){
    vector<vector<int>> edges={{5,0},{5,2},{2,3},{3,1},{4,0},{4,1}};
    int V=6;
    Solution obj;
    auto res=obj.topoSortDFS(edges,V);
    for(auto&x:res){
        cout<<x<<" ";
    }
   
    
    return 0;
}


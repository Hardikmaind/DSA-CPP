#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
        bool checkConnectedComponenets(int src,vector<int>&color,vector<vector<int>>&adjlist){
            queue<int>q;
            q.push(src);
            color[src]=1;
            while(!q.empty()){
                int node=q.front(); q.pop();
                for(auto& x:adjlist[node]){
                    if(!color[x]){
                        color[x]=color[node]==1?-1:1;     // i con also do this color[x]=-color[node]. assigning opposite color
                        q.push(x);
                    }else if(color[x]==color[node]){
                        return false;
                    }
                }
            }
            return true;
        }
      public:
        bool isBipartite(int V, vector<vector<int>> &edges) {
            // Code here
             vector<vector<int>>adjlist(V);
             for(auto &x:edges){
                 adjlist[x[0]].push_back(x[1]);
                 adjlist[x[1]].push_back(x[0]);
             }
             
             vector<int>color(V,0);
             for(int i=0;i<V;i++){
                 if(!color[i]){
                     if(!checkConnectedComponenets(i,color,adjlist)){       //! if cond false return false
                         return false;
                     }
                 }
             }
             return true;
        }
    };

    int main(){
        int V=5;
        vector<vector<int>>edges={{0,1},{1,2},{2,3},{3,4},{4,0}};       //5 vertices cycle. therefore not a bipartite graph
        Solution obj;
        cout<<boolalpha<<obj.isBipartite(V,edges);
        return 0;
    }
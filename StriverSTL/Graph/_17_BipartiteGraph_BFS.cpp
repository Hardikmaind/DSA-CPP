#include <bits/stdc++.h>
using namespace std;

//* PROPERTILES OF BIPARTITE GRAPH
// ! Linear graph with no cycle are always bipartite graphs
//! any graph with even cycle length(no of edges/no of vertices) is also bipartite
//? Any graph with ODD LENGTH CYCLE can never be bipartite
// ! BFS and DFS can be used to check if a graph is bipartite
// ! Vertex Partitioning :The vertex set of a bipartite graph can be partitioned into two disjoint subsets, A and B, such that every edge connects a vertex in A to a vertex in B. 

/*

A complete bipartite graph, denoted as Km,n, is a bipartite graph where every vertex in one set is connected to every vertex in the other set. 
A tree is always bipartite. 
A path is a bipartite graph. 
A cycle with an even number of vertices is bipartite. 

*/



//! this is my method. i have used vis array instead of the color array. initialsied the vis array with 0 instead of -1 . and used the 1 as red color and -1 as green color. because of this i can direct check !vis[x] instead of vis[x]==-1. if a node is already visited or not.
class Solution {
    private:
    //* this method is there becasue our graph can have multiple components. to check all the components . this func is there
        bool check(int start,vector<vector<int>>& adjlist,vector<int>&vis){
            queue<int>q;
            q.push(start);
            vis[start]=1;       //1 means red,-1 means green
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto x:adjlist[node]){
                    if(!vis[x]){
                        vis[x]=vis[node]==1?-1:1;
                        q.push(x);
                    }else if(vis[x]==vis[node]){
                        return false;
                    }
                }
            }
            return true;
        }
    public:
        bool isBipartite(vector<vector<int>>& adjlist) {
            vector<int>vis(adjlist.size(),0);
            for(int i=0;i<adjlist.size();i++){
                if(!vis[i]){
                    if(check(i,adjlist,vis)==false){
                        return false;
                    }
                }
            }
            return true;
        }
    };


    //! this is strivers code. he named the vis array as color. initialsied the color array with -1 instead of 0 . and used the 0 as red color and 1 as green color. because of this i can direct check color[x]==-1 instead of !vis[x]. if a node is already visited or not.
class Solution2{
    private:
    //* this method is there becasue our graph can have multiple components. to check all the components . this func is there
        bool check(int start,vector<vector<int>>& adjlist,vector<int>&color){
            queue<int>q;
            q.push(start);
            color[start]=0;       //0 as red ,1 as green
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto x:adjlist[node]){
                    if(color[x]==-1){
                        color[x]=!color[node]; // if color[node] is 0 then color[x] will be 1 and vice versa
                        q.push(x);
                    }else if(color[x]==color[node]){
                        return false;
                    }
                }
            }
            return true;
        }
    public:
        bool isBipartite(vector<vector<int>>& adjlist) {
            vector<int>color(adjlist.size(),-1);
            for(int i=0;i<adjlist.size();i++){
                if(color[i]==-1){
                    if(check(i,adjlist,color)==false){
                        return false;
                    }
                }
            }
            return true;
        }


};
    int main(){
        Solution obj;
        Solution2 obj2;
        vector<vector<int>>adjlist={{1,2,3},{0,2},{0,1,3},{0,2}};
        cout<<boolalpha<<obj.isBipartite(adjlist)<<endl; 
        cout<<boolalpha<<obj2.isBipartite(adjlist)<<endl; 

        return 0;
    }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//* tc is O(V+E) and no toposort vector is used, simply used the count to tracking if the all the nodes are counted or not. if count ==V then no cycle is present.
class Solution{
    public:
        bool kahn_topoSort_algo(int V,vector<vector<int>> &edge){
            vector<vector<int>> adjlist(V);
            vector<int>indegree(V);
            for(auto &x:edge){
                adjlist[x[0]].push_back(x[1]);
                indegree[x[1]]++;
            }
            queue<int>q;
            for(auto &x:indegree){
                if(x==0){
                    q.push(x);
                }
            }
            int count=0;        //! taking the count variable instead of the toposort vector. since we dont have to return the toposorted vector
            while(!q.empty()){
                int node=q.front();
                q.pop();
                count++;            //! used the counter instead of the toposorted vector, since here we dont need to find the toposorted vector.
                for(auto x:adjlist[node]){

                    indegree[x]--;      //reduce the indegree
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }
            }
            return count==V?false:true;         // we can also return directly count!=V; but this is more readable.

            return true;
        }
};


//* tc is O(V+E) and sc is O(V) for the toposort vector and O(V) for the indegree vector
class Solution2{
    public:
        bool kahn_topoSort_algo(int V,vector<vector<int>> &edge){
            vector<vector<int>> adjlist(V);
            vector<int>indegree(V);
            for(auto &x:edge){
                adjlist[x[0]].push_back(x[1]);
                indegree[x[1]]++;
            }
            queue<int>q;
            for(auto &x:indegree){
                if(x==0){
                    q.push(x);
                }
            }
            vector<int>toposorted;
            int count=0;        //! taking the count variable instead of the toposort vector. since we dont have to return the toposorted vector
            while(!q.empty()){
                int node=q.front();
                q.pop();
                toposorted.push_back(node);          //! used the counter instead of the toposorted vector, since here we dont need to find the toposorted vector.
                for(auto x:adjlist[node]){

                    indegree[x]--;      //reduce the indegree
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }
            }
            return toposorted.size()==V?false:true;         // we can also return directly count!=V; but this is more readable.

            return true;
        }
};

int main()
{
    vector<vector<int>> edges={{0,1},{0,2},{1,2},{2,3}};
    int V = 4;

    Solution obj;
    auto res = obj.kahn_topoSort_algo(V, edges);
    cout <<boolalpha<<res<< endl;
    
    
    Solution2 obj2;
    auto res2 = obj2.kahn_topoSort_algo(V, edges);
    cout <<boolalpha<<res2<< endl;
    

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; // Define INF as a large value

class Solution{
    public:
        vector<int>dijkstraAlgo(int src,vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;         //? here pair is pair<int,int>  (adjnode,wt)
            vector<int>dist(adj.size(),INF);
            dist[src]=0;
            pq.push({src,0});
            while(!pq.empty()){
                int node=pq.top().first;
                int wt=pq.top().second;
                pq.pop();
                for(const auto &[adjnode,wt]:adj[node]){
                    if(dist[node]+wt<dist[adjnode]){
                        dist[adjnode]=dist[node]+wt;
                        pq.push({adjnode,dist[adjnode]});
                    }
                }

            }
            return dist;
        }



};

int main(){
    Solution obj;
                    // vertex  wt
    vector<vector<pair<int,int>>>adjlist={{{1,4},{2,4}},{{0,4},{2,2}},{{0,4},{1,2},{3,3},{4,1},{5,6}},{{2,3},{5,2}},{{2,1},{5,3}},{{2,6},{3,2},{4,3}}};
    auto res=obj.dijkstraAlgo(0,adjlist);
    for(auto &x:res){
        cout<<x<<endl;
    }
    return 0;
}
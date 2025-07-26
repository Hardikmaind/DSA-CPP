#include <bits/stdc++.h>
using namespace std;    


const int INF = 1e9; // Define INF as a large value

class Solution{
    public:
        vector<int>dijkstraAlgo(int src,vector<vector<pair<int,int>>>&adj){
            set<pair<int,int>> st;
            vector<int>dist(adj.size(),INF);
            dist[src]=0;
            st.insert({0,src}); // {distance, node}
            while(!st.empty()){
                auto it = *(st.begin()); // Get the node with the smallest distance
                int wt = it.first; // Get the distance of that node
                int node = it.second; // Get the node with the smallest distance

                st.erase(st.begin()); // Remove the node from the set
                for(const auto &[adjnode,edgewt]:adj[node]){
                    if(dist[node]+edgewt<dist[adjnode]){
                        // If the node was already in the set, remove it
                        if(dist[adjnode] != INF){
                            st.erase({dist[adjnode], adjnode});
                        }
                        dist[adjnode]=dist[node]+edgewt;
                        st.insert({dist[adjnode], adjnode});
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
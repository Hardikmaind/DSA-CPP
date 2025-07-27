#include <bits/stdc++.h>
using namespace std;


// Dijkstra's algorithm to find the shortest path in a graph
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u - 1].push_back({v - 1, w});
            adj[v - 1].push_back({u - 1, w});
        }

        const int INF = 1e9;
        set<pair<int, int>> st;  // {dist, node}
        vector<int> dist(n, INF);
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        dist[0] = 0;
        st.insert({0, 0});

        while (!st.empty()) {
            int d = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[adjNode]) {
                    if (dist[adjNode] != INF) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dist[node] + wt;
                    parent[adjNode] = node;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n - 1] == INF)
            return {-1};

        // Recover path
        vector<int> path;
        int node = n - 1;
        while (parent[node] != node) {
            path.push_back(node + 1); // back to 1-based index
            node = parent[node];
        }
        path.push_back(1); // push the source (1-based)
        path.push_back(dist[n - 1]); 
        

        reverse(path.begin(), path.end());

        // we can also do this after reversing the vector, and then add at the first position
        // path.insert(path.begin(), dist[n - 1]);

        return path;
    }
};


//! here below i have taken the adjlist of n+1 size and parent vector of n+1 size

class Solution2 {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u ].push_back({v , w});
            adj[v ].push_back({u , w});
        }

        const int INF = 1e9;
        set<pair<int, int>> st;  // {dist, node}
        vector<int> dist(n, INF);
        vector<int> parent(n+1);
        for (int i = 1; i < n; i++) parent[i] = i;

        dist[1] = 0;
        st.insert({0, 1}); // start from node 1 (1-based index)

        while (!st.empty()) {
            int d = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[adjNode]) {
                    if (dist[adjNode] != INF) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dist[node] + wt;
                    parent[adjNode] = node;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n ] == INF)
            return {-1};

        // Recover path
        vector<int> path;
        int node = n ;
        while (parent[node] != node) {
            path.push_back(node ); 
            node = parent[node];
        }
        path.push_back(1); 
        path.push_back(dist[n]); 
        

        reverse(path.begin(), path.end());

        // we can also do this after reversing the vector, and then add at the first position
        // path.insert(path.begin(), dist[n]);

        return path;
    }
};



int main(){
    Solution sol;
    Solution2 sol2;
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {2, 5, 5},
        {2, 3, 4},
        {5, 3, 1},
        {4, 3, 3}
    };
    
    vector<int> result = sol.shortestPath(n, m, edges);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> result2 = sol2.shortestPath(n, m, edges);
    
    for (int x : result2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = (int)1e9 + 7;
        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        vector<vector<pair<int, int>>> adjlist(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            adjlist[u].push_back({v, d});
            adjlist[v].push_back({u, d});
        }

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
             if (wt > dist[node]) continue; // ✅ Skip outdated paths

            for (auto& it : adjlist[node]) {
                int adjnode = it.first;
                int weight = it.second;

                if (dist[node] + weight < dist[adjnode]) {
                    dist[adjnode] = dist[node]  + weight;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                } else if (dist[node] + weight == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1]%mod;
    }
};



int main(){
    Solution sol;
    int n = 7;
    vector<vector<int>> roads = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},

        {2, 4, 1},
        {3, 4, 2},
        {3, 5, 1},
        {4, 5, 3},
        {5, 6, 1},
        {4, 6, 5}
    };
    cout << sol.countPaths(n, roads) << endl; // Output: 4
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;     
        vector<vector<pair<int, int>>> adjlist(n);
        for (int i = 0; i < flights.size(); ++i) {
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];
            adjlist[u].push_back({v, p});
        }
        pq.push({0, {0, src}});
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9)); // track cost at each stop count
        dist[src][0] = 0;
        while (!pq.empty()) {
            int cost = pq.top().first;
            int step = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if (node == dst) return cost;
            if (step > k) continue;
            for (auto &adjnode : adjlist[node]) {
                int next = adjnode.first;
                int price = adjnode.second;
                if (cost + price < dist[next][step + 1]) {
                    dist[next][step + 1] = cost + price;
                    pq.push({dist[next][step + 1], {step + 1, next}});
                }
            }
        }
        return -1;
    }
};

//! this solutino uses tuple and alias. see how we have used pii for pair and tuple in priority queue( because we dont have method .first and .second for tuple)
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using pii = pair<int, int>;
        using tii = tuple<int, int, int>; // cost, stops, node

        vector<vector<pii>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        // Min-heap: (cost, stops, node)
        priority_queue<tii, vector<tii>, greater<>> pq;
        pq.push({0, 0, src});

        // Track best number of stops to reach a node
        vector<int> minStops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, stops, node] = pq.top(); pq.pop();

            if (node == dst) return cost;
            if (stops > k || stops > minStops[node]) continue;

            minStops[node] = stops;

            for (auto& [nei, price] : adj[node]) {
                pq.push({cost + price, stops + 1, nei});
            }
        }

        return -1;
    }
};


int main(){
    Solution sol;
    int n = 3; // number of nodes
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0; // source node
    int dst = 2; // destination node
    int k = 1; // maximum number of stops
    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << result << endl; // Expected output: 200

    Solution2 sol2;
    result = sol2.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price using Solution2: " << result << endl; // Expected output: 200

    return 0;   
}
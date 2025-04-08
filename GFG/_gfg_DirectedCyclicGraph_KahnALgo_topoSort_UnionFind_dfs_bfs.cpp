#include <bits/stdc++.h>
using namespace std;

//! Kahn’s Algorithm (BFS-style Topo Sort)
class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and indegree array
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Push all nodes with indegree 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If not all nodes were processed, cycle exists
        return count != V;
    }
};

// !  Bonus: Print the actual cycle using DFS
class Solution2 {
    public:
        bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& parent, vector<int>& cycle) {
            visited[node] = true;
            recStack[node] = true;
    
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    parent[neighbor] = node;
                    if (dfs(neighbor, adj, visited, recStack, parent, cycle)) return true;
                } else if (recStack[neighbor]) {
                    // Cycle found — backtrack to extract the cycle
                    int curr = node;
                    cycle.push_back(neighbor);
                    while (curr != neighbor) {
                        cycle.push_back(curr);
                        curr = parent[curr];
                    }
                    cycle.push_back(neighbor);
                    reverse(cycle.begin(), cycle.end());
                    return true;
                }
            }
    
            recStack[node] = false;
            return false;
        }
    
        bool isCyclicWithCyclePrint(int V, vector<vector<int>>& edges) {
            vector<vector<int>> adj(V);
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
            }
    
            vector<bool> visited(V, false), recStack(V, false);
            vector<int> parent(V, -1);
            vector<int> cycle;
    
            for (int i = 0; i < V; ++i) {
                if (!visited[i]) {
                    if (dfs(i, adj, visited, recStack, parent, cycle)) {
                        // Print the cycle
                        cout << "Cycle detected: ";
                        for (int node : cycle)
                            cout << node << " ";
                        cout << endl;
                        return true;
                    }
                }
            }
    
            cout << "No cycle found." << endl;
            return false;
        }
    };
    

int main()
{
    //! Kahn’s Algorithm (BFS-style Topo Sort)
    
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    int v = 4;
    cout << boolalpha << obj.isCyclic(v, edges) << endl;



    // !  Bonus: Print the actual cycle using DFS

    Solution2 obj2;
    cout<<boolalpha<<obj2.isCyclicWithCyclePrint(v,edges)<<endl;
    return 0;
}
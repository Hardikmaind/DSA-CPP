#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>

template <typename T>
class Graph {
public:
    std::unordered_map<T, std::list<T>> adj; // Adjacency list

    // Add Edge
    void addEdge(T u, T v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) { // Undirected graph
            adj[v].push_back(u);
        }
    }

    // BFS Traversal
    void BFS(T start) {
        std::queue<T> q;
        std::unordered_map<T, bool> visited;

        q.push(start);
        visited[start] = true;

        std::cout << "BFS Traversal: ";
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            std::cout << node << " ";

            for (T neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    // DFS Traversal
    void DFSUtil(T node, std::unordered_map<T, bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";

        for (T neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(T start) {
        std::unordered_map<T, bool> visited;
        std::cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        std::cout << std::endl;
    }

    // Find Connected Components
    int findConnectedComponents() {
        std::unordered_map<T, bool> visited;
        int count = 0;

        for (auto it : adj) {
            if (!visited[it.first]) {
                count++;
                std::cout << "Component " << count << ": ";
                DFSUtil(it.first, visited);
                std::cout << std::endl;
            }
        }

        return count;
    }
};

int main() {
    Graph<int> g;
    
     // Hardcoded complex graph input
     g.addEdge(0, 1, 0);
     g.addEdge(0, 2, 0);
     g.addEdge(1, 3, 0);
     g.addEdge(1, 4, 0);
     g.addEdge(2, 5, 0);
     g.addEdge(3, 6, 0);
     g.addEdge(4, 6, 0);
     g.addEdge(5, 7, 0);
     g.addEdge(6, 7, 0);
     g.addEdge(6, 8, 0);
     g.addEdge(7, 9, 0);
     g.addEdge(8, 9, 0);
     g.addEdge(10, 11, 0); // Separate component
     g.addEdge(11, 12, 0);
     g.addEdge(12, 10, 0);
     
     int start = 0; // Starting node for BFS and DFS

    g.BFS(start);
    g.DFS(start);

    int components = g.findConnectedComponents();
    std::cout << "Total Connected Components: " << components << std::endl;

    return 0;
}

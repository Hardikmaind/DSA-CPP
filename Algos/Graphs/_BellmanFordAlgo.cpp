
#include <bits/stdc++.h>
using namespace std;

// Include all the definitions (structs and functions) from the previous sections
// You would ideally put these in separate header files or compile them together.
// For this comprehensive answer, I'll assume they are in the same file for demonstration.

// --- Start of combined definitions for Bellman-Ford ---

// Constants for Infinity (using distinct names to avoid conflicts if all combined)
const int INF_GLOBAL = numeric_limits<int>::max();

// --- Directed, Weighted Graph (Edge List) ---
struct EdgeDirectedWeighted
{
    int source, destination, weight;
};
bool bellmanFord_DirectedWeighted_EdgeList(int start_node, int num_nodes, const vector<EdgeDirectedWeighted> &edges, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Negative cycle detected in Directed, Weighted Graph (Edge List)!" << endl;
            return false;
        }
    }
    return true;
}
void run_DirectedWeighted_EdgeList()
{
    cout << "\n--- Directed, Weighted Graph (Edge List) ---" << endl;
    int num_nodes = 5;
    vector<EdgeDirectedWeighted> edges;
    cout << "Example 1: No negative cycle" << endl;
    edges.clear();
    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({4, 3, -3});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_DirectedWeighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
    cout << endl;
    cout << "Example 2: With negative cycle" << endl;
    edges.clear();
    edges.push_back({0, 1, 1});
    edges.push_back({1, 2, -1});
    edges.push_back({2, 0, -1});
    edges.push_back({0, 3, 10});
    if (bellmanFord_DirectedWeighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Directed, Unweighted Graph (Edge List) ---
struct EdgeDirectedUnweighted
{
    int source, destination;
};
bool bellmanFord_DirectedUnweighted_EdgeList(int start_node, int num_nodes, const vector<EdgeDirectedUnweighted> &edges, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = 1;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = 1;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Logical inconsistency detected (likely a negative cycle if weights could be negative and were unit). For true unweighted, this should not happen." << endl;
            return false;
        }
    }
    return true;
}
void run_DirectedUnweighted_EdgeList()
{
    cout << "\n--- Directed, Unweighted Graph (Edge List) ---" << endl;
    int num_nodes = 5;
    vector<EdgeDirectedUnweighted> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_DirectedUnweighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Undirected, Weighted Graph (Edge List) ---
struct EdgeUndirectedWeighted
{
    int source, destination, weight;
};
bool bellmanFord_UndirectedWeighted_EdgeList(int start_node, int num_nodes, const vector<EdgeUndirectedWeighted> &input_edges, vector<int> &distances)
{
    vector<EdgeUndirectedWeighted> directed_edges;
    for (const auto &edge : input_edges)
    {
        directed_edges.push_back({edge.source, edge.destination, edge.weight});
        directed_edges.push_back({edge.destination, edge.source, edge.weight});
    }
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : directed_edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : directed_edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Negative cycle detected in Undirected, Weighted Graph (Edge List)!" << endl;
            return false;
        }
    }
    return true;
}
void run_UndirectedWeighted_EdgeList()
{
    cout << "\n--- Undirected, Weighted Graph (Edge List) ---" << endl;
    int num_nodes = 4;
    vector<EdgeUndirectedWeighted> edges;
    cout << "Example 1: No negative cycle" << endl;
    edges.clear();
    edges.push_back({0, 1, 1});
    edges.push_back({1, 2, 2});
    edges.push_back({0, 2, 4});
    edges.push_back({2, 3, 1});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_UndirectedWeighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
    cout << endl;
    cout << "Example 2: With negative cycle (due to negative edge)" << endl;
    edges.clear();
    edges.push_back({0, 1, -5});
    edges.push_back({1, 2, 2});
    if (bellmanFord_UndirectedWeighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Undirected, Unweighted Graph (Edge List) ---
struct EdgeUndirectedUnweighted
{
    int source, destination;
};
bool bellmanFord_UndirectedUnweighted_EdgeList(int start_node, int num_nodes, const vector<EdgeUndirectedUnweighted> &input_edges, vector<int> &distances)
{
    vector<EdgeUndirectedUnweighted> directed_edges;
    for (const auto &edge : input_edges)
    {
        directed_edges.push_back({edge.source, edge.destination});
        directed_edges.push_back({edge.destination, edge.source});
    }
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : directed_edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = 1;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : directed_edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = 1;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Logical inconsistency detected (should not happen for true unweighted graphs)." << endl;
            return false;
        }
    }
    return true;
}
void run_UndirectedUnweighted_EdgeList()
{
    cout << "\n--- Undirected, Unweighted Graph (Edge List) ---" << endl;
    int num_nodes = 4;
    vector<EdgeUndirectedUnweighted> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({0, 2});
    edges.push_back({2, 3});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_UndirectedUnweighted_EdgeList(start_node, num_nodes, edges, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Directed, Weighted Graph (Adjacency List) ---
struct AdjEdgeWeighted
{
    int to, weight;
};
struct EdgeExtracted
{
    int u, v, w;
};
bool bellmanFord_DirectedWeighted_AdjList(int start_node, int num_nodes, const vector<vector<AdjEdgeWeighted>> &adj, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    vector<EdgeExtracted> all_edges;
    for (int u = 0; u < num_nodes; ++u)
        for (const auto &edge : adj[u])
            all_edges.push_back({u, edge.to, edge.weight});
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : all_edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.w;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : all_edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.w;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Negative cycle detected in Directed, Weighted Graph (Adjacency List)!" << endl;
            return false;
        }
    }
    return true;
}
void run_DirectedWeighted_AdjList()
{
    cout << "\n--- Directed, Weighted Graph (Adjacency List) ---" << endl;
    int num_nodes = 5;
    vector<vector<AdjEdgeWeighted>> adj(num_nodes);
    cout << "Example 1: No negative cycle" << endl;
    adj.assign(num_nodes, vector<AdjEdgeWeighted>());
    adj[0].push_back({1, -1});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 2});
    adj[1].push_back({4, 2});
    adj[3].push_back({2, 5});
    adj[4].push_back({3, -3});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_DirectedWeighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
    cout << endl;
    cout << "Example 2: With negative cycle" << endl;
    adj.assign(num_nodes, vector<AdjEdgeWeighted>());
    adj[0].push_back({1, 1});
    adj[1].push_back({2, -1});
    adj[2].push_back({0, -1});
    adj[0].push_back({3, 10});
    if (bellmanFord_DirectedWeighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Directed, Unweighted Graph (Adjacency List) ---
struct AdjEdgeUnweighted
{
    int to;
};
struct EdgeExtractedUnweighted
{
    int u, v;
};
bool bellmanFord_DirectedUnweighted_AdjList(int start_node, int num_nodes, const vector<vector<AdjEdgeUnweighted>> &adj, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    vector<EdgeExtractedUnweighted> all_edges;
    for (int u = 0; u < num_nodes; ++u)
        for (const auto &edge : adj[u])
            all_edges.push_back({u, edge.to});
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : all_edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = 1;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : all_edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = 1;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Logical inconsistency detected (should not happen for true unweighted graphs)." << endl;
            return false;
        }
    }
    return true;
}
void run_DirectedUnweighted_AdjList()
{
    cout << "\n--- Directed, Unweighted Graph (Adjacency List) ---" << endl;
    int num_nodes = 5;
    vector<vector<AdjEdgeUnweighted>> adj(num_nodes);
    adj[0].push_back({1});
    adj[0].push_back({2});
    adj[1].push_back({3});
    adj[2].push_back({3});
    adj[3].push_back({4});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_DirectedUnweighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Undirected, Weighted Graph (Adjacency List) ---
struct AdjEdgeWeightedUndirected
{
    int to, weight;
};
struct EdgeExtractedUndirectedWeighted
{
    int u, v, w;
};
bool bellmanFord_UndirectedWeighted_AdjList(int start_node, int num_nodes, const vector<vector<AdjEdgeWeightedUndirected>> &adj, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    vector<EdgeExtractedUndirectedWeighted> all_directed_edges;
    for (int u = 0; u < num_nodes; ++u)
        for (const auto &edge : adj[u])
            all_directed_edges.push_back({u, edge.to, edge.weight});
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : all_directed_edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.w;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : all_directed_edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.w;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Negative cycle detected in Undirected, Weighted Graph (Adjacency List)!" << endl;
            return false;
        }
    }
    return true;
}
void run_UndirectedWeighted_AdjList()
{
    cout << "\n--- Undirected, Weighted Graph (Adjacency List) ---" << endl;
    int num_nodes = 4;
    vector<vector<AdjEdgeWeightedUndirected>> adj(num_nodes);
    cout << "Example 1: No negative cycle" << endl;
    adj.assign(num_nodes, vector<AdjEdgeWeightedUndirected>());
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_UndirectedWeighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
    cout << endl;
    cout << "Example 2: With negative cycle (due to negative edge)" << endl;
    adj.assign(num_nodes, vector<AdjEdgeWeightedUndirected>());
    adj[0].push_back({1, -5});
    adj[1].push_back({0, -5});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    if (bellmanFord_UndirectedWeighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- Undirected, Unweighted Graph (Adjacency List) ---
struct AdjEdgeUnweightedUndirected
{
    int to;
};
struct EdgeExtractedUnweightedUndirected
{
    int u, v;
};
bool bellmanFord_UndirectedUnweighted_AdjList(int start_node, int num_nodes, const vector<vector<AdjEdgeUnweightedUndirected>> &adj, vector<int> &distances)
{
    distances.assign(num_nodes, INF_GLOBAL);
    distances[start_node] = 0;
    vector<EdgeExtractedUnweightedUndirected> all_directed_edges;
    for (int u = 0; u < num_nodes; ++u)
        for (const auto &edge : adj[u])
            all_directed_edges.push_back({u, edge.to});
    for (int i = 0; i < num_nodes - 1; ++i)
    {
        bool relaxed_in_this_iteration = false;
        for (const auto &edge : all_directed_edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = 1;
            if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                relaxed_in_this_iteration = true;
            }
        }
        if (!relaxed_in_this_iteration)
            break;
    }
    for (const auto &edge : all_directed_edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = 1;
        if (distances[u] != INF_GLOBAL && distances[u] + weight < distances[v])
        {
            cout << "Logical inconsistency detected (should not happen for true unweighted graphs)." << endl;
            return false;
        }
    }
    return true;
}
void run_UndirectedUnweighted_AdjList()
{
    cout << "\n--- Undirected, Unweighted Graph (Adjacency List) ---" << endl;
    int num_nodes = 4;
    vector<vector<AdjEdgeUnweightedUndirected>> adj(num_nodes);
    adj[0].push_back({1});
    adj[1].push_back({0});
    adj[1].push_back({2});
    adj[2].push_back({1});
    adj[0].push_back({2});
    adj[2].push_back({0});
    adj[2].push_back({3});
    adj[3].push_back({2});
    int start_node = 0;
    vector<int> distances;
    if (bellmanFord_UndirectedUnweighted_AdjList(start_node, num_nodes, adj, distances))
    {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 0; i < num_nodes; ++i)
            cout << "To node " << i << ": " << (distances[i] == INF_GLOBAL ? "Infinity" : to_string(distances[i])) << endl;
    }
}

// --- End of combined definitions for Bellman-Ford ---

int main()
{
    // Call each test function
    run_DirectedWeighted_EdgeList();
    run_DirectedUnweighted_EdgeList();
    run_UndirectedWeighted_EdgeList();
    run_UndirectedUnweighted_EdgeList();
    run_DirectedWeighted_AdjList();
    run_DirectedUnweighted_AdjList();
    run_UndirectedWeighted_AdjList();
    run_UndirectedUnweighted_AdjList();

    return 0;
}
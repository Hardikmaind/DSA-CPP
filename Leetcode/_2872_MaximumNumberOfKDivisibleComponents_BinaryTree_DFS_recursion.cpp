#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-k-divisible-components/solutions/6156598/maximum-number-of-k-divisible-components


class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};

int main(){
    int n=5;
    vector<vector<int>>edges={{0,2},{1,2},{1,3},{2,4}};
    vector<int>values={1,8,1,4,4};
    int k=6;


    Solution* solution = new Solution();
    int res = solution->maxKDivisibleComponents(n, edges,values, k);
    cout<<res<<endl;
}


/*Approach 1: Depth-First-Search (DFS)
Intuition
To solve this problem, let’s consider how the structure of a tree can help us.

A tree consists of nodes connected by edges, and each edge connects a parent node to one of its children. Once we pick a node as the root, we can break the tree down into smaller parts, called subtrees, based on the parent-child relationships. The tree is undirected, so we can choose any node to be the root without affecting the result.

Now, let’s think about how we can use recursion to solve this. We want to calculate the sum of each subtree. After calculating the sum, we need to check: Is this sum divisible by k? If it is, we can detach the subtree at that point because it forms a valid component.

But what if the sum isn’t divisible by k? In that case, we need to "carry over" the remainder (the leftover part when divided by k) to the parent node. This way, the parent node can combine its remainder with its children's remainders to check if the total sum becomes divisible by k. This recursive process naturally fits a Depth-First Search (DFS) approach:

Start from the leaves of the tree (the smallest subtrees) and compute their sums.
Propagate the results up to their parent nodes, adding up the remainders modulo k.
Whenever a subtree's sum is divisible by k, count it as a valid component.
For a more comprehensive understanding of depth-first search, check out the DFS Explore Card 🔗. This resource provides an in-depth look at DFS, explaining its key concepts and applications with a variety of problems to solidify understanding of the pattern.

Algorithm
maxKDivisibleComponents function:

Initialize an adjacency list adjList to represent the graph.
Populate adjList using the given edges.
Initialize componentCount to 0, which will store the count of k-divisible components.
Call dfs(0, -1, adjList, values, k, componentCount) starting from node 0 with no parent (-1).
Return componentCount as the result.
dfs function:

Initialize sum to 0, representing the sum of node values in the current subtree.
For each neighborNode of currentNode:
If neighborNode is not equal to parentNode, recursively call dfs for neighborNode with currentNode as its parent.
Add the result of the recursive call to sum and take modulo k.
Add the value of currentNode (nodeValues[currentNode]) to sum and take modulo k.
If sum is 0, increment componentCount because the current subtree forms a k-divisible component.
Return sum to allow the parent node to incorporate the result.*/
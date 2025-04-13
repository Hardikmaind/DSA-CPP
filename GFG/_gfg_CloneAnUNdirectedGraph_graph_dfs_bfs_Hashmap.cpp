#include <bits/stdc++.h>
using namespace std;



struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
    public:
      Node* cloneGraph(Node* node) {
          // code here
          if (node == nullptr) return nullptr;
          unordered_map<Node*, Node*> mp; // Maps original nodes to their clones
          queue<Node*> q;
          // Clone the first node and put it in the map and queue
          Node* clone = new Node(node->val);
          mp[node] = clone;
          q.push(node);
          while (!q.empty()) {
              Node* curr = q.front();
              q.pop();
              for (Node* neighbor : curr->neighbors) {
                  if (mp.find(neighbor) == mp.end()) {
                      // Clone the neighbor if it hasn't been cloned yet
                      mp[neighbor] = new Node(neighbor->val);
                      q.push(neighbor);
                  }
                  // Add the cloned neighbor to the current node's clone's neighbors
                  mp[curr]->neighbors.push_back(mp[neighbor]);
              }
          }
          return mp[node]; // Return the clone of the starting node
      }
  };

  //! this below is the traversal of the graph using BFS
  void printGraphBFS(Node* node) {
    if (!node) return;
    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        for (Node* neighbor : curr->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}


//! this below is the cloning of the graph using DFS
class Solution2 {
    public:
        Node* cloneGraph(Node* node) {
            if (!node) return nullptr;
    
            unordered_map<Node*, Node*> clones;
            return dfs(node, clones);
        }
    
        Node* dfs(Node* node, unordered_map<Node*, Node*>& clones) {
            if (clones.find(node) != clones.end()) {
                return clones[node]; // already cloned
            }
    
            // Clone the current node
            Node* cloneNode = new Node(node->val);
            clones[node] = cloneNode;
    
            // Recursively clone neighbors
            for (Node* neighbor : node->neighbors) {
                cloneNode->neighbors.push_back(dfs(neighbor, clones));
            }
    
            return cloneNode;
        }
    };
    

  int main(){
    //! here i have created a graph
      Node* node=new Node(0);
      node->neighbors.push_back(new Node(1));
      node->neighbors.push_back(new Node(2));
      Node* node2=new Node(1);
      node2->neighbors.push_back(new Node(0));
      Node* node3=new Node(2);
      node3->neighbors.push_back(new Node(0));
      
      Solution bfscloner;
      auto res=bfscloner.cloneGraph(node);
      printGraphBFS(res);

      cout<<endl;

      Solution2 dfscloner;
      auto res2=dfscloner.cloneGraph(node);
      printGraphBFS(res2);
      return 0;
      
  }
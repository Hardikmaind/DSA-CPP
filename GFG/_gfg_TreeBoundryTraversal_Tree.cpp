#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }
    void addLeftBoundary(Node* node, vector<int>& boundary) {
        Node* curr = node->left;
        while (curr) {
            if (!isLeaf(curr)) boundary.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(Node* node, vector<int>& boundary) {
        if (node == NULL) return;
        if (isLeaf(node)) {
            boundary.push_back(node->data);
            return;
        }
        addLeaves(node->left, boundary);
        addLeaves(node->right, boundary);
    }
    void addRightBoundary(Node* node, vector<int>& boundary) {
        vector<int> temp;
        Node* curr = node->right;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            boundary.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node* root) {
        vector<int> boundary;
        if (root == NULL) return boundary;
        if (!isLeaf(root)) boundary.push_back(root->data);
        addLeftBoundary(root, boundary);
        addLeaves(root, boundary);
        addRightBoundary(root, boundary);
        return boundary;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    Solution obj;
    vector<int> boundary = obj.boundaryTraversal(root);
    for (int i = 0; i < boundary.size(); i++) {
        cout << boundary[i] << " ";
    }
    cout << endl;
    return 0;

}
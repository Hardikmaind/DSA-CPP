#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        vector<int> result;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                Node* node = q.front();
                q.pop();
                // Insert node data at correct position
                int index = leftToRight ? i : n - i - 1;
                level[index] = node->data;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // Add this level to result
            for (int val : level) {
                result.push_back(val);
            }
            // Toggle direction
            leftToRight = !leftToRight;
        }
        return result;
    }
};

int main(){
    Solution obj;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = obj.findSpiral(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
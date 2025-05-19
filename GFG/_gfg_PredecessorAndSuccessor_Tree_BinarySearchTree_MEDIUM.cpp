#include <bits/stdc++.h>
using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    void inorderTraversal(Node* root, vector<Node*>& inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root);
        inorderTraversal(root->right, inorder);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();

        for (int i = 0; i < n; ++i) {
            if (inorder[i]->data == key) {
                Node* pre = (i > 0) ? inorder[i - 1] : nullptr;
                Node* suc = (i + 1 < n) ? inorder[i + 1] : nullptr;
                return {pre, suc};
            }
        }
        // If exact key not found, find floor and ceil (predecessor/successor)
        Node* pre = nullptr;
        Node* suc = nullptr;
        for (int i = 0; i < n; ++i) {
            if (inorder[i]->data < key) pre = inorder[i];
            if (inorder[i]->data > key && suc == nullptr) {
                suc = inorder[i];
                break;
            }
        }
        return {pre, suc};
    }
};

int main(){
    // Example usage
    Node* root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(9);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(10);

    Solution sol;
    vector<Node*> result = sol.findPreSuc(root, 8);
    cout << "Predecessor: " << (result[0] ? result[0]->data : -1) << endl;
    cout << "Successor: " << (result[1] ? result[1]->data : -1) << endl;

    return 0;
}
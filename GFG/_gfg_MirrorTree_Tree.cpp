#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }

        mirror(node->left);
        mirror(node->right);

        std::swap(node->left, node->right);
    }
};



// ! below is the code for inorder traversal of the tree
void print(Node* root){
    if(root == nullptr){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);  
    root->left->right = new Node(5);

    print(root);
    cout<<endl;
    sol.mirror(root);
    print(root);
    return 0;
}
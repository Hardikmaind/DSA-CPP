#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
       if(node==nullptr){
           return -1;
       }
       int lh=height(node->left);
       int rh=height(node->right);
       return max(lh,rh)+1;
    }
     int height2(Node* node) {
        // code here
       if(node==nullptr){
           return -1;
       }
       
       return max(height(node->left),height(node->right))+1;
    }
};

int main(){
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);
    root->right->right->left=new Node(6);
    root->right->right->right=new Node(7);
    cout<<sol.height(root);
    cout<<endl;
    cout<<sol.height2(root);
    return 0;
}
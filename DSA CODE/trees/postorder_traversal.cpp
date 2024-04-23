#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node* right;
    Node(int val){
        data=val;
        left = right = nullptr;
    }
};
void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data<<" ";
    
}
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

cout<<"this is the postorder traversal:=> "<<endl;
    postorder(root);
    return 0;
}
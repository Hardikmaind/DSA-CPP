#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
  public:
    vector<int> arr, leaf;
    
    void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        arr.push_back(node->data);
        if(!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }
    
    bool isDeadEnd(Node *root)
    {
        arr = {0}; 
        leaf = {};
        inorder(root);
        
        int j = 0;
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
            if(arr[i] == leaf[j]){
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }
        
        return false;
    }
};

int main(){
    Solution s;
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->right = new Node(12);
    
    if(s.isDeadEnd(root))
        cout << "The BST has a dead end." << endl;
    else
        cout << "The BST does not have a dead end." << endl;

    return 0;
}
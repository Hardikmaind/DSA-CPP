#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
  void dfs(Node*root,vector<vector<int>>&res,vector<int>&path){
      if(!root){
          return ;
      }
      
      path.push_back(root->data);
      
      if(!root->left && !root->right){
          res.push_back(path);
      }else {
          dfs(root->left,res,path);
          dfs(root->right,res,path);
      }
      
      path.pop_back();
      
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<vector<int>>res;
        vector<int>path;
        
        dfs(root,res,path);
        return res;
        
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
    vector<vector<int>> result = obj.Paths(root);   
    for (const auto& path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
    
}
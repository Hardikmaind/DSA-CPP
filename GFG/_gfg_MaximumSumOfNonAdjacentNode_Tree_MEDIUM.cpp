#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      int solve(Node* root,unordered_map<Node*,int>&mp){
          if(root == nullptr)return 0;
          if(mp.find(root) !=mp.end())return mp[root];
          int nontake = solve(root->left,mp)+solve(root->right,mp);
          int take = root->data;
          if(root->left){
              take += solve(root->left->left,mp);
              take += solve(root->left->right,mp);
          }
          if(root->right){
              take += solve(root->right->left,mp);
              take += solve(root->right->right,mp);
          }
          return mp[root] = max(take,nontake);
      }
      int getMaxSum(Node *root) {
          // code here
          unordered_map<Node*,int>mp;
          return solve(root,mp);
      }
  };

  int main(){
        // Example usage
        Node* root = new Node();
        root->data = 11;
        root->left = new Node();
        root->left->data = 1;
        root->right = new Node();
        root->right->data = 2;
    
        Solution sol;
        cout << sol.getMaxSum(root) << endl; // Output: 40
        return 0;
  }
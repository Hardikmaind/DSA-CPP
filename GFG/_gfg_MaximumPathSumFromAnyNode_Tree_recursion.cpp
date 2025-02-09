#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
    public:
    int findMaxPathSum(Node* root, int &maxSum) {
      if (!root) return 0;
  
      
      int left =  max(0,findMaxPathSum(root->left, maxSum));
      int right = max(0,findMaxPathSum(root->right, maxSum));
  
      
      int maxTop = root->data + left + right;
  
      
      maxSum = max(maxSum, maxTop);
  
      
      return root->data + max(left, right);
  }
      
      int findMaxSum(Node *root) {
          // code here
          int maxSum=INT_MIN;
           findMaxPathSum( root, maxSum);
           return maxSum;
          
      }
  };

  int main(){
    Node * root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;
    cout<<obj.findMaxSum(root);
    return 0;
  }
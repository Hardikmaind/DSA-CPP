#include <bits/stdc++.h>
using namespace std;

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
      bool isHeap(Node* root) {
          // code here
          if (!root) return true;
  
          queue<Node*> q;
          q.push(root);
      
          bool nullSeen = false; // To check completeness
      
          while (!q.empty()) {
              Node* curr = q.front();
              q.pop();
      
              // Check left child
              if (curr->left) {
                  if (nullSeen || curr->data < curr->left->data) {
                      return false;
                  }
                  q.push(curr->left);
              } else {
                  nullSeen = true;
              }
      
              // Check right child
              if (curr->right) {
                  if (nullSeen || curr->data < curr->right->data) {
                      return false;
                  }
                  q.push(curr->right);
              } else {
                  nullSeen = true;
              }
          }
      
          return true;
          
      }
  };


  int main(){
    Solution obj;
    Node* root=new Node(97);
    root->left=new Node(46);
    root->right=new Node(37);
    root->left->left=new Node(12);
    root->left->right=new Node(3);
    root->right->left=new Node(7);
    root->right->right=new Node(31);
    root->left->left->left=new Node(6);
    root->left->left->right=new Node(9);
    
    cout<<boolalpha<<obj.isHeap(root)<<endl;
    return 0;
  }
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    int height(Node* root,int &max_dia)
    {
        if(!root) return 0;
        int lh=height(root->left,max_dia);
        int rh=height(root->right,max_dia);
        max_dia=max(max_dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) 
    {
       if(!root) return 0;
       int dia=0;
       height(root,dia);
       return dia;
    }
};

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    Solution obj;
    cout<<obj.diameter(root);
    return 0;

}
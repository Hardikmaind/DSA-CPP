#include <bits/stdc++.h>
using namespace std;


struct Node{
int data;
Node *left,*right;

Node(int data){
    this->data = data;
    left = right = nullptr;
}
};
class Solution{
  public:
     vector<int> verticalSum(Node *root) {
        map<int, int> map;
        int rootLevel = 0;
        preorder(root, map, rootLevel);
        vector<int> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }

    void preorder(Node *root, map<int, int>& map, int level) {
        if (root == nullptr) {
            return;
        }
        map[level] += root->data;
        preorder(root->left, map, level - 1);
        preorder(root->right, map, level + 1);
    }

    
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution obj;
    vector<int> result = obj.verticalSum(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
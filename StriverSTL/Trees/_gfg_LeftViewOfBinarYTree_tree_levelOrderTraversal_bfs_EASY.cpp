#include <bits/stdc++.h>
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
    vector<int> leftView(Node *root) {
        vector<int> res;
        if (root == nullptr) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();

                // Capture the first node of the level
                if (i == 0)
                    res.push_back(curr->data);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return res;
    }
};


int main(){
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> leftView = sol.leftView(root);

    for (int val : leftView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
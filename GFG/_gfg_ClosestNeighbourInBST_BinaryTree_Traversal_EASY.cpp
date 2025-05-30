#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; 
class Solution {
  public:

    int findMaxFork(Node* root, int k) {
        int res = -1;  // Or some default "not found" value

        while (root != nullptr) {
            if (root->data == k) {
                return root->data;
            }
            if (root->data < k) {
                res = root->data;  // update possible answer
                root = root->right;
            } else {
                root = root->left;
            }
        }

        return res;
    }
};
int main(){
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution sol;
    int k = 6;
    int result = sol.findMaxFork(root, k);
    
    cout << "Closest value less than or equal to " << k << " is: " << result << endl;

    return 0;
}

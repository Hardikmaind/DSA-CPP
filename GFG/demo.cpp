#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
}; // Don't forget the semicolon here

class Solution {
public:
    //Function to return a tree created from postorder and inorder traversals.
    Node* buildTree(int in[], int post[], int n) {
        if (n <= 0) {
            return nullptr;
        }
        return helper(in, post, 0, n - 1, 0, n - 1);
    }

    Node* helper(int in[], int post[], int inst, int inend, int pst, int pend) {
        if (inst > inend || pst > pend) {
            return nullptr;
        }
        
        int rootvalue = post[pend];
        Node* root = new Node(rootvalue);
        
        int rootindex = -1;
        for (int i = inst; i <= inend; i++) {
            if (in[i] == rootvalue) {
                rootindex = i;
                break;
            }
        }
        
        root->left = helper(in, post, inst, rootindex - 1, pst, pst + (rootindex - inst) - 1);
        root->right = helper(in, post, rootindex + 1, inend, pst + (rootindex - inst), pend - 1);
        
        return root;
    }
};

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Your code here!
    Solution sol; // Corrected the object creation
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);
    Node* root = sol.buildTree(in, post, n); // Changed sol to sol
    cout << "preOrder Traversal of the tree is: ";
    preOrder(root);
    cout << endl;
    return 0;
}

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
    void dfs(Node* node, int currentSum, int currentLength, int &maxSum, int &maxLength) {
        if (node == nullptr) return;

        currentSum += node->data;
        currentLength++;

        // If it's a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxSum = currentSum;
            } else if (currentLength == maxLength) {
                maxSum = max(maxSum, currentSum);
            }
            return;
        }

        dfs(node->left, currentSum, currentLength, maxSum, maxLength);
        dfs(node->right, currentSum, currentLength, maxSum, maxLength);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxSum = 0;
        int maxLength = 0;
        dfs(root, 0, 0, maxSum, maxLength);
        return maxSum;
    }
};


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);

    Solution solution;
    int result = solution.sumOfLongRootToLeafPath(root);
    cout << "Sum of nodes on the longest path: " << result << endl;

    return 0;
}
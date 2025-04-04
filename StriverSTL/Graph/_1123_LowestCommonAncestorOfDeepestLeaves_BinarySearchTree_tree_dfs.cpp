#include <bits/stdc++.h>
using namespace std;


class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        pair<TreeNode*, int> dfs(TreeNode* root) {
            if (!root) {
                return {nullptr, 0};
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            if (left.second > right.second) {
                return {left.first, left.second + 1};
            }
            if (left.second < right.second) {
                return {right.first, right.second + 1};
            }
            return {root, left.second + 1};
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).first; }
    };

    int main(){
        Solution s;
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);  
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);

        TreeNode* result = s.lcaDeepestLeaves(root);
        cout << "Lowest Common Ancestor of Deepest Leaves: " << result->val << endl; // Output: 2
    }
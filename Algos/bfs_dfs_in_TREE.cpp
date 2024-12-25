#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // BFS Traversal
    vector<int> BFS(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return result;
    }


    //!Normal Preorder Traversal returning a vector of integers

    vector<int> NormalPreorder(TreeNode* root){

        if(!root) return {};
        vector<int> result;
        result.push_back(root->val);
        vector<int> left = NormalPreorder(root->left);
        vector<int> right = NormalPreorder(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

    // DFS Preorder Traversal
    vector<int> Preorder(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);

            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return result;
    }

    //!Normal Inorder Traversal returning a vector of integers
    vector<int> NormalInorder(TreeNode* root){
        if(!root) return {};
        vector<int> result;
        vector<int> left = NormalInorder(root->left);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        vector<int> right = NormalInorder(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

    // DFS Inorder Traversal
    vector<int> Inorder(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current || !s.empty()) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }

    //!Normal Postorder Traversal returning a vector of integers
    vector<int> NormalPostorder(TreeNode* root){
        if(!root) return {};
        vector<int> result;
        vector<int> left = NormalPostorder(root->left);
        vector<int> right = NormalPostorder(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root->val);
        return result;
    }

    // DFS Postorder Traversal
    vector<int> Postorder(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }

    // Level Order Traversal
    vector<vector<int>> LevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> bfs = sol.BFS(root);
    vector<int> preorder = sol.Preorder(root);
    vector<int> inorder = sol.Inorder(root);
    vector<int> postorder = sol.Postorder(root);
    vector<vector<int>> levelOrder = sol.LevelOrder(root);

    // Print results
    cout << "BFS: ";
    for (int val : bfs) cout << val << " ";
    cout << "\nPreorder: ";
    for (int val : preorder) cout << val << " ";
    cout << "\nInorder: ";
    for (int val : inorder) cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : postorder) cout << val << " ";
    cout << "\nLevel Order:\n";
    for (const auto& level : levelOrder) {
        for (int val : level) cout << val << " ";
        cout << "\n";
    }
    //print normal traversals
    cout << "Normal Preorder: ";
    vector<int> normal_preorder = sol.NormalPreorder(root);
    for (int val : normal_preorder) cout << val << " ";
    cout << "\nNormal Inorder: ";
    vector<int> normal_inorder = sol.NormalInorder(root);   
    for (int val : normal_inorder) cout << val << " ";
    cout << "\nNormal Postorder: ";
    vector<int> normal_postorder = sol.NormalPostorder(root);
    for (int val : normal_postorder) cout << val << " ";
    return 0;
}

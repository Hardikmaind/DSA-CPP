#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
//!this is level order traversal. see the file ../Algos/bfs_dfs_in_TREE.cpp for more details
    vector<int> largestValues(TreeNode* root) {
          vector<vector<int>> result;
        if (!root) return {};

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
        vector<int>res;
        for(auto &arr:result){
            int maxele=*max_element(arr.begin(),arr.end());
            res.push_back(maxele);
        }
        return res;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);

    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);

    root->right->right=new TreeNode(9);

    auto res=s.largestValues(root);
    for(auto &ele:res){
        cout<<ele<<" ";
    }
}
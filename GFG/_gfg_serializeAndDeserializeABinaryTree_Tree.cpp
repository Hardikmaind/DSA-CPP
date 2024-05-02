#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    vector<int> serialize(Node *root)
    {
        vector<int> v;
        inorder(root, v);
        return v;
    }
    Node *buildtree(vector<int> &v, vector<int>::iterator start, vector<int>::iterator end)
    {
        if (start == end)
            return nullptr;
        auto mid = start + (end - start) / 2;
        Node *root = new Node(*mid);
        root->left = buildtree(v, start, mid);
        root->right = buildtree(v, mid + 1, end);
        return root;
    }
    Node *deSerialize(vector<int> &v)
    {
        return buildtree(v, v.begin(), v.end());
    }
};

int main()
{
    Solution sol;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    vector<int> v = sol.serialize(root);
    for (int &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    Node *newRoot = sol.deSerialize(v);
    return 0;
}
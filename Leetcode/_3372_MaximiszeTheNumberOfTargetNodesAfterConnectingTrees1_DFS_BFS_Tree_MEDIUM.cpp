#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/solutions/6759732/maximize-the-number-of-target-nodes-after-connecting-trees-i


class Solution {
public:
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxCount2 = *max_element(count2.begin(), count2.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}};
    int k = 1;
    vector<int> result = sol.maxTargetNodes(edges1, edges2, k);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
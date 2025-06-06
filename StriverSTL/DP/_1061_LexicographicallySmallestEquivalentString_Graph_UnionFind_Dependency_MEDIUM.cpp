#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6812060/cpp-java-python-dfs-100-beats-easy-to-understand
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6812007/unionfind-vs-dfs-for-the-equivalent-relation-beats-100


// tc is O(n + m) where n is the length of s1 and s2, and m is the length of baseStr. sc is O(1) for the dfs approach.
class Solution {
public:
    // DFS to find the smallest lex character in the component
    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<int>& vis) {
        vis[cur - 'a'] = 1;
        char minChar = cur;
        for (char neighbor : adj[cur]) {
            if (vis[neighbor - 'a'] == 0) {
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;

        // Step 1: Build the equivalence graph
        for (int i = 0; i < n; ++i) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Replace each character in baseStr with the smallest equivalent
        string result;
        for (char ch : baseStr) {
            vector<int> vis(26, 0);
            char minChar = dfs(adj, ch, vis);
            result.push_back(minChar);
        }

        return result;
    }
};


//! here i have used a DFS approach. But I have created the adjacency list using a vector of vectors instead of an unordered_map.
class Solution3 {
public:
    // DFS to find the smallest lexicographical character in the connected component
    char dfs(vector<vector<int>>& adj, int cur, vector<int>& vis) {
        vis[cur] = 1;
        char minChar = cur + 'a';

        for (int neighbor : adj[cur]) {
            if (!vis[neighbor]) {
                char candidate = dfs(adj, neighbor, vis);
                minChar = min(minChar, candidate);
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        vector<vector<int>> adj(26); // 26 lowercase letters

        // Step 1: Build the equivalence graph
        for (int i = 0; i < n; ++i) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Replace each character in baseStr with the smallest equivalent
        string result;
        for (char ch : baseStr) {
            int idx = ch - 'a';
            vector<int> vis(26, 0);
            char minChar = dfs(adj, idx, vis);
            result.push_back(minChar);
        }

        return result;
    }
};


//! Union-Find approach . tc is O(n + m) where n is the length of s1 and s2, and m is the length of baseStr. and sc is O(1) for the UnionFind class.

class UnionFind { // A simple version for UnionFind class
    vector<int> root;
public:
    UnionFind(int n):root(n) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) { //Path compression
        return (x==root[x]) ? x : root[x] = Find(root[x]);
    }

    void Union(int x, int y) {// the smaller one as the common root
        x= Find(x), y= Find(y);
        if (x == y) return;
        else if (x<y) root[y]=x;  
        else root[x]=y;  
    }
};
class Solution2 {
public:
    string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
        UnionFind G(26);
        const int n=s1.size(), m=baseStr.size();
        for(int i=0; i<n; i++)
            G.Union(s1[i]-'a', s2[i]-'a');
        
        string ans(m, ' ');
        for(int i=0; i<m; i++)
            ans[i]='a'+G.Find(baseStr[i]-'a');
        return ans;
    }
};


int main(){
    //! test with DFS
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    Solution sol;
    string result = sol.smallestEquivalentString(s1, s2, baseStr);
    cout << result << endl; // Output: "makkek"
    
    //! Test with UnionFind
    string s1_uf = "abc", s2_uf = "cde", baseStr_uf = "fgh";
    Solution2 sol_uf;
    string result_uf = sol_uf.smallestEquivalentString(s1_uf, s2_uf, baseStr_uf);
    cout << result_uf << endl; // Output: "fgh"

    //! test with DFS using vector of vectors
    string s1_dfs = "abc", s2_dfs = "cde", baseStr_dfs = "fgh";
    Solution3 sol_dfs;
    string result_dfs = sol_dfs.smallestEquivalentString(s1_dfs, s2_dfs, baseStr_dfs);
    cout << result_dfs << endl; // Output: "fgh"
    
    
    return 0;
}
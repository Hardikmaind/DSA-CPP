#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6812060/cpp-java-python-dfs-100-beats-easy-to-understand
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6812007/unionfind-vs-dfs-for-the-equivalent-relation-beats-100

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

/*
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
class Solution {
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
*/
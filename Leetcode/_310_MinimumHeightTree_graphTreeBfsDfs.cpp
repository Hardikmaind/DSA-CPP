/*
    Company Tags                : GOOGLE
*/


//NOTE : You can do a brute force to do DFS from each node treating them as root and keep finding the Height in every case. That will give TLE.

/**************************************************** C++ ********************************************/
//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(n);
        map<int, vector<int>> adj;
        
        for(vector<int> vec:edges) {
            int u = vec[0];
            int v = vec[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) //adding all leafs node so that we can remove them later
                que.push(i);
        }
        
        while(n > 2) {
            int size = que.size();
            n -= size; //removing nodes with indegreee 1
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};

int main(){
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    Solution obj;
    vector<int> result = obj.findMinHeightTrees(4, edges);
    for(int i : result)
        cout << i << " ";
    vector<vector<int>> edges2 =  { { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 4 }, { 5, 4 } };
    cout<<endl;
    vector<int> result2 = obj.findMinHeightTrees(6, edges2);
    for(int i : result2)
        cout << i << " ";
    return 0;
}
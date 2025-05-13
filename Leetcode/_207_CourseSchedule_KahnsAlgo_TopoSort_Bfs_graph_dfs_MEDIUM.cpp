#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto&x:prerequisites){
            adjlist[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        int countOfVertices=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            countOfVertices++;
            for(auto &x:adjlist[node]){
                indegree[x]--;
                if(!indegree[x]){
                    q.push(x);
                }
            }
        }
        return countOfVertices==numCourses?true:false;
    }
};

int main(){
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}
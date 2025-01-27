#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule-iv/solutions/6285082/course-schedule-iv
class Solution {
public:
    // Performs DFS and returns true if there's a path between src and target
    // and false otherwise.
    bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
                        vector<bool>& visited, int src, int target) {
        visited[src] = 1;

        if (src == target) {
            return true;
        }

        int answer = false;
        for (auto adj : adjList[src]) {
            if (!visited[adj]) {
                answer =
                    answer || isPrerequisite(adjList, visited, adj, target);
            }
        }
        return answer;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<bool> answer;
        for (auto q : queries) {
            // Reset the visited array for each query.
            vector<bool> visited(numCourses, false);
            answer.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
        }

        return answer;
    }
};

int main(){
    Solution a;
    vector<vector<int>> prerequisites = {{1,0}};
    vector<vector<int>> queries = {{0,1},{1,0}};
    vector<bool> res = a.checkIfPrerequisite(3, prerequisites, queries);
    for (int i = 0; i < res.size(); i++){
        cout <<boolalpha<< res[i] << " ";
    }
    return 0;
}
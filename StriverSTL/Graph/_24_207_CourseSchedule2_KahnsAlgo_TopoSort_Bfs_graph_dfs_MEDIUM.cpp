#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlist(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>topoSort;
        queue<int>q;
        for(auto &x:prerequisites){
            adjlist[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            topoSort.push_back(node);
            for(auto x:adjlist[node]){
                indegree[x]--;
                if(!indegree[x]){
                    q.push(x);
                }
            }
        }
        
        // return (topoSort.size() == numCourses) ? topoSort : vector<int>();  I can also do like this, returning empty vector using vector constructor.

        return topoSort.size()==numCourses?topoSort:*new vector<int>();         //* here i return  the topoSort vector if it is equal to numCourses otherwise i return an empty vector. I create the empty vector using new keyword and then i dereference it to return the empty vector. Though This is not a good practice and should be avoided. Instead, i should return an empty vector directly.
    }
};

//! I have below returned the pointer to the vector<int> ,which I have created using new keyword.
vector<int>* newVector(int size) {
    return new vector<int>(size);
}

int main(){
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{1,2},{0,1}};
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    for(int i : result) {
        cout << i << " ";
    }


    auto res=newVector(5);
    for(int i=0;i<5;i++){
        (*res)[i]=i;        //yaha initialize kiya and then niche print kiya
        cout<<(*res)[i]<<" ";
    }

    return 0;
}
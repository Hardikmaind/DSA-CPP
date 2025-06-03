#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        int n = status.size();
        vector<bool> visited(n, false);   // To avoid processing same box again
        vector<bool> boxAvailable(n, false); // Box we have in our possession
        queue<int> q;
        for (int box : initialBoxes) {
            boxAvailable[box] = true;
            if (status[box] == 1) {
                q.push(box);
                visited[box] = true;
            }
        }
        int totalCandies = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            totalCandies += candies[curr];
            // Collect keys and unlock new boxes
            for (int key : keys[curr]) {
                if (status[key] == 0) {
                    status[key] = 1;  // unlock
                    if (boxAvailable[key] && !visited[key]) {
                        q.push(key);
                        visited[key] = true;
                    }
                }
            }
            // Collect contained boxes
            for (int box : containedBoxes[curr]) {
                boxAvailable[box] = true;
                if (status[box] == 1 && !visited[box]) {
                    q.push(box);
                    visited[box] = true;
                }
            }
        }
        return totalCandies;
    }
};


int main(){
    Solution sol;
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {5, 10, 15, 20};
    vector<vector<int>> keys = {{}, {0}, {}, {}};
    vector<vector<int>> containedBoxes = {{1}, {}, {3}, {}};
    vector<int> initialBoxes = {0};

    int result = sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies you can get: " << result << endl; // Output: 25
    return 0;
    
}
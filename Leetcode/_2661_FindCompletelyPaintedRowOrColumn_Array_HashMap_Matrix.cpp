#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/first-completely-painted-row-or-column/solutions/6301353/first-completely-painted-row-or-column
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        unordered_map<int, pair<int, int>> numToPos;
        // Populate numToPos map by iterating over the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = numToPos[num];
            mat[row][col] = -mat[row][col];  // mark as seen

            // Check if the row or column is completely painted
            if (checkRow(row, mat) || checkColumn(col, mat)) {
                return i;
            }
        }

        return -1;  // This line will never be reached as per the problem
                    // statement
    }

private:
    bool checkRow(int row, vector<vector<int>>& mat) {
        // Return true if row is completely seen
        for (int col = 0; col < mat[0].size(); col++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }

    bool checkColumn(int col, vector<vector<int>>& mat) {
        // Return true if col is completely seen
        for (int row = 0; row < mat.size(); row++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4}, {2,3}};
    cout << sol.firstCompleteIndex(arr, mat) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool searchMatrix(const vector<vector<int>>& mat, int x) {
    if (mat.empty() || mat[0].empty()) return false;

    int rows = mat.size();
    int cols = mat[0].size();
    
    int i = 0;        // Start from the first row
    int j = cols - 1; // Start from the last column

    while (i < rows && j >= 0) {
        if (mat[i][j] == x) {
            return true;
        } else if (mat[i][j] > x) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }

    return false; // Element not found
    }

};
int main(){
    Solution s;
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    cout<<s.searchMatrix(mat,3);
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    if (n == 0) return false; 
    int m = mat[0].size();
    if (m == 0) return false;

    for (int i = 0; i < n; ++i) {
        if (x >= mat[i][0] && x <= mat[i][m - 1]) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == x) {
                    return true;
                } else if (mat[i][mid] < x) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }

    return false;
}

};

int main(){
    Solution s;
    vector<vector<int>> mat={{3,4,9},{2,5,6},{9,25,27}};
    bool res=s.searchRowMatrix(mat,9);
    cout<<res<<endl;
}
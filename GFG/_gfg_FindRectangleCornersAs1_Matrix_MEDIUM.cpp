#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Iterate over all pairs of rows
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int commonOnes = 0;

                // Check for matching 1s in the same columns of both rows
                //! iterating over m columns
                for (int col = 0; col < m; ++col) {
                    if (mat[i][col] == 1 && mat[j][col] == 1) {
                        commonOnes++;
                        if (commonOnes >= 2) {
                            return true; // Found a rectangle
                        }
                    }
                }
            }
        }

        return false;
    }
};


int main(){
    Solution ob;
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };

    auto result = ob.ValidCorner(matrix);
    cout<<boolalpha<<result<<endl; // Expected output: true
    return 0;
}
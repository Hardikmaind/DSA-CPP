#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int> elements_mat2;
        int count = 0;

        // Flatten mat2 into a set for O(1) lookups
        for (const auto &row : mat2) {
            for (int val : row) {
                elements_mat2.insert(val);
            }
        }

        // For each element in mat1, check if (x - val) exists in mat2
        for (const auto &row : mat1) {
            for (int val : row) {
                if (elements_mat2.count(x - val)) {
                    count++;
                }
            }
        }

        return count;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    vector<vector<int>> mat2 = {{5, 6}, {7, 8}};
    int x = 10;
    int result = sol.countPairs(mat1, mat2, x);
    cout << "Count of pairs: " << result << endl; // Expected output: 2 (1+9 and 2+8)
    return 0;
}
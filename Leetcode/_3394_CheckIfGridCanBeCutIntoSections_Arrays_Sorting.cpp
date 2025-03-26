#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/solutions/6525276/minimum-operations-to-make-a-uni-value-grid

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            // Try both horizontal and vertical cuts
            return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
        }
    
    private:
        // Check if valid cuts can be made in a specific dimension
        bool checkCuts(vector<vector<int>>& rectangles, int dim) {
            int gapCount = 0;
    
            // Sort rectangles by their starting coordinate in the given dimension
            sort(rectangles.begin(), rectangles.end(),
                 [dim](const vector<int>& a, const vector<int>& b) {
                     return a[dim] < b[dim];
                 });
    
            // Track the furthest ending coordinate seen so far
            int furthestEnd = rectangles[0][dim + 2];
    
            for (size_t i = 1; i < rectangles.size(); i++) {
                vector<int>& rect = rectangles[i];
    
                // If current rectangle starts after the furthest end we've seen,
                // we found a gap where a cut can be made
                if (furthestEnd <= rect[dim]) {
                    gapCount++;
                }
    
                // Update the furthest ending coordinate
                furthestEnd = max(furthestEnd, rect[dim + 2]);
            }
    
            // We need at least 2 gaps to create 3 sections
            return gapCount >= 2;
        }
    };
    int main(){
        Solution s;
        vector<vector<int>> rectangles = {{0, 0, 2, 2}, {1, 1, 3, 3}, {2, 2, 4, 4}};
        cout << s.checkValidCuts(3, rectangles) << endl;
        return 0;
        
    }
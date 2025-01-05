#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftAmount(n + 1, 0); // Difference array
        
        // Process each shift operation
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                shiftAmount[start] += 1;
                shiftAmount[end + 1] -= 1;
            } else {
                shiftAmount[start] -= 1;
                shiftAmount[end + 1] += 1;
            }
        }
        
        // Calculate cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftAmount[i];
            int newChar = ((s[i] - 'a' + cumulativeShift) % 26 + 26) % 26; // Handle wrap-around
            s[i] = 'a' + newChar;
        }
        
        return s;
    }
};

int main() {
    Solution obj;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1},{0,2,1}};
    cout << obj.shiftingLetters(s, shifts);
}
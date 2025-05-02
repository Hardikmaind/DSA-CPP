#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i = 0;
        // Add sentinels to handle edge cases more easily
        result = 'L' + result + 'R';
        n = result.size();
        int left = 0;
        for (int right = 1; right < n; ++right) {
            if (result[right] == '.') continue;
    
            // Now result[left] and result[right] are not '.'
            if (result[left] == result[right]) {
                // Fill the middle with the same direction
                for (int k = left + 1; k < right; ++k) {
                    result[k] = result[left];
                }
            } else if (result[left] == 'R' && result[right] == 'L') {
                // Fill inward from both ends
                int l = left + 1;
                int r = right - 1;
                while (l < r) {
                    result[l++] = 'R';
                    result[r--] = 'L';
                }
            }
            // else: 'L...R' → no change
    
            left = right;
        }
        // Remove the added sentinels
        return result.substr(1, n - 2);
    }
    
    };


    int main(){
        Solution obj;
        string dominoes = ".L.R...LR..L..";
        cout << obj.pushDominoes(dominoes) << endl; // Output: "LL.RR.LLRRLL.."
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/solutions/4190834/unique-length-3-palindromic-subsequences
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.countPalindromicSubsequence("aabca") << endl;
    return 0;
}
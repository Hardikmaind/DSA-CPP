#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/solutions/6778146/greedy-o-n-l-word-matrix-o-n-with-images-example-walkthrough-c-python-java


//tc is O(n*L)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (string w : words) mpp[w]++;

        int count = 0, alreadyPalindrome = 0;
        for (auto& [w, freq] : mpp) {
            string s = w;
            reverse(s.begin(), s.end());
            if (w == s) {
                count += (freq / 2) * 4;
                if (freq % 2) alreadyPalindrome = 1;
            } else if (w < s && mpp.count(s)) {
                count += min(freq, mpp[s]) * 4;
            }
        }
        return count + alreadyPalindrome * 2;
    }
};

// tc is O(n)
class Solution2 {
public:
    int longestPalindrome(vector<string>& words, int count = 0) {
        vector<vector<int>> mpp(26, vector<int>(26, 0));
        int middle = 0;

        for (auto &s : words) {
            int x = s[0] - 'a', y = s[1] - 'a';
            if (mpp[y][x] > 0) {
                mpp[y][x]--;
                count += 4;
                if (x == y) middle--;
            } else {
                mpp[x][y]++;
                if (x == y) middle++;
            }
        }

        if (middle > 0) count += 2;
        return count;
    }
};


int main(){
    Solution sol;
    vector<string> words = {"lc", "cl", "gg", "gg"};
    cout << sol.longestPalindrome(words) << endl; // Output: 8

    Solution2 sol2;
    cout << sol2.longestPalindrome(words) << endl; // Output: 8
    
    return 0;
}
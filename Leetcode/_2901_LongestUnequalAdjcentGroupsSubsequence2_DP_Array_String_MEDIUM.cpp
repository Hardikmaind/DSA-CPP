#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/solutions/6735770/longest-unequal-adjacent-groups-subsequence-ii

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
        vector<string> ans;
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ans.emplace_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};


int main(){
    Solution sol;
    vector<string> words = {"abc", "abd", "acd", "xyz"};
    vector<int> groups = {1, 2, 1, 3};
    vector<string> result = sol.getWordsInLongestSubsequence(words, groups);
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
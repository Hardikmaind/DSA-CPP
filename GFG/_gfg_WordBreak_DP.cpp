#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool wordBreak(string &s, vector<string> &dictionary) {
            unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
            int n = s.size();
    
            // Find the max word length to limit unnecessary checks
            int maxWordLength = 0;
            for (string word : dictionary) {
                maxWordLength = max(maxWordLength, (int)word.length());
            }
    
            vector<bool> dp(n + 1, false);
            dp[0] = true;  // Base case
    
            for (int i = 1; i <= n; i++) {
                for (int j = max(0, i - maxWordLength); j < i; j++) { // Only check up to maxWordLength
                    if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                        dp[i] = true;
                        break; // No need to check further
                    }
                }
            }
            return dp[n];
        }
    };

    int main(){
        string s="ilike";
        vector<string>dictionary={"i","like","gfg"};
        Solution ob;
        cout<<boolalpha<<ob.wordBreak(s,dictionary)<<endl;
    }
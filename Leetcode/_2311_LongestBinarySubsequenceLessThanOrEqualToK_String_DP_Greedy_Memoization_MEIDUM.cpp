#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    string s = "1001010";
    int k = 5;
    cout << sol.longestSubsequence(s, k) << endl; // Output: 5
    return 0;
}
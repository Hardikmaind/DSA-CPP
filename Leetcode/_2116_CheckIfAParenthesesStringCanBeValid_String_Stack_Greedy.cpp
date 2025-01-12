#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/solutions/6245791/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.size();
        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }

        stack<int> openBrackets, unlocked;

        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < length; i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining open brackets with unlocked characters
        while (!openBrackets.empty() && !unlocked.empty() &&
               openBrackets.top() < unlocked.top()) {
            openBrackets.pop();
            unlocked.pop();
        }

        if (!openBrackets.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s = "))()))";
    string locked = "010100";
    cout << sol.canBeValid(s, locked) << endl;
    return 0;
}
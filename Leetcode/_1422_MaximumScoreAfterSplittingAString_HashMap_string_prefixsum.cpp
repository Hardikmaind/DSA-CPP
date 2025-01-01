#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int sum1 = 0; // Count of '1's in the string
        for (char c : s) {
            if (c == '1') {
                sum1++;
            }
        }

        int maxScore = 0;
        int count0 = 0, count1 = sum1;

        // Iterate through the string, dividing it into two parts
        for (int i = 0; i < n - 1; i++) { // Ensure left and right are non-empty
            if (s[i] == '0') {
                count0++;
            } else {
                count1--;
            }
            maxScore = max(maxScore, count0 + count1);
        }

        return maxScore;
    }
};


int main(){
    Solution obj;
    string s = "011101";
    cout << obj.maxScore(s) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubstrings(string &s) {
        // Final answer to store the sum of all substrings
        int ans = 0;              
        // Length of the input string
        int n = s.size();         

        // Iterate through each starting index of substring
        for (int i = 0; i < n; i++) {
            // Temporary variable to hold current substring value
            int temp = 0;        

            // Generate all substrings starting from index i
            for (int j = i; j < n; j++) {
                // Shift the previous value by one digit to the left
                temp *= 10;                       
                // Add current digit to form the number
                temp += (s[j] - '0');             
                // Add the current substring number to the answer
                ans += temp;                      
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "6759";
    cout << obj.sumSubstrings(s) << endl; // Output: 1670
    return 0;
}

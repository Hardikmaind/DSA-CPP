#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if (n == 1) return "1";

        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int len = result.size();
            for (int j = 0; j < len;) {
                char digit = result[j];
                int count = 0;
                // Count consecutive identical digits
                while (j < len && result[j] == digit) {
                    count++;
                    j++;
                }
                // Append count and digit to the current string
                current += to_string(count) + digit;
            }
            result = current;
        }
    
        return result;
    }
};

int main(){
    Solution obj;
    int n=5; // Example input
    string result = obj.countAndSay(n);
    cout << result << endl; // Output the result
    return 0;
}
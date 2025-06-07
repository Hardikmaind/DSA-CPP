#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> res;
        int d = 256;        // number of characters in input alphabet
        int q = 101;        // a prime number to mod the hash
        int m = pat.size();
        int n = txt.size();

        if (m > n) return res;

        int p = 0; // hash value for pattern
        int t = 0; // hash value for text
        int h = 1;

        // The value of h would be "pow(d, m-1) % q"
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate hash value for pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check hash values of current window and pattern
            if (p == t) {
                // Check characters one by one
                if (txt.substr(i, m) == pat)
                    res.push_back(i + 1);
            }

            // Calculate hash value for next window
            if (i < n - m) {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;

                // Convert negative hash to positive
                if (t < 0)
                    t = (t + q);
            }
        }

        return res;
    }
};

//! below code is brute force solution
class Solution2 {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> res;
        int patsize = pat.size();
        int txtsize = txt.size();
        for (int i = 0; i <= txtsize - patsize; i++) {  // use <=
            if (txt.substr(i, patsize) == pat) {
                res.push_back(i + 1); // 1-based indexing
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    vector<int> result = sol.search(pat, txt);
    
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    // Testing brute force solution
    Solution2 sol2;
    vector<int> result2 = sol2.search(pat, txt);
    
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
    
}

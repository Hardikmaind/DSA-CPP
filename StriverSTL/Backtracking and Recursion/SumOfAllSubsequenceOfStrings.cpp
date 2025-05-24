#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void helper(string& s, int index, string current, long long& sum) {
        if (index == s.size()) {
            if (!current.empty()) {
                sum += stoll(current); // convert to number and add to sum      //! here stoll is used to convert string to long long integer
            }
            return;
        }

        // Include current character
        helper(s, index + 1, current + s[index], sum);

        // Exclude current character
        helper(s, index + 1, current, sum);
    }

    long long demo(string& s) {
        long long sum = 0;
        helper(s, 0, "", sum);
        return sum;
    }
};
int main(){
    Solution obj;
    string s = "123";
    long long result = obj.demo(s);
    cout << result << endl; // Output: 6 (1 + 2 + 3 + 12 + 13 + 23 + 123)

    cout<<endl;
    cout<<"below i have converted the string into the number with the help of 'stoll' function"<<endl;
    string s2 = "451235435436";
    long long int num=stoll(s2);
    cout<<num<<endl;
    return 0;
}

// Why we need the current string:
// We’re trying to find the sum of all numeric values of all non-empty subsequences of the string s. These values are not just individual digits — they are full numbers formed by concatenating digits in subsequences.


/*
⚠️ What happens if we try to skip current?
If you just write something like:

sum += s[index] - '0';
you'd only be adding individual digits, not full number subsequences like "12" or "123". That would result in an incorrect total.


Summary:
You must build the full number as a string (or as digits in-place) to correctly form numbers like "12" and "123".
Once the full subsequence is formed (in the current string), you convert it to an integer using stoll(current) and add it to sum.
*/
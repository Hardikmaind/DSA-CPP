#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function to find the largest number after k swaps.
    void findMaximum(string &str, int k, string &max_str, int idx) {
    if (k == 0)
        return;

    int n = str.size();

    char max_digit = str[idx];
    for (int i = idx + 1; i < n; ++i) {
        if (str[i] > max_digit)
            max_digit = str[i];
    }

    // If max_digit is not greater than current, no point in swapping
    if (max_digit != str[idx])
        k--;

    for (int i = n - 1; i >= idx; --i) {
        if (str[i] == max_digit) {
            swap(str[idx], str[i]);

            if (str.compare(max_str) > 0)
                max_str = str;

            findMaximum(str, k, max_str, idx + 1);

            swap(str[idx], str[i]); // backtrack
        }
    }
}

string findMaximumNum(string str, int k) {
    string max_str = str;
    findMaximum(str, k, max_str, 0);
    return max_str;
}
};


int main() {
    Solution obj;
    string str = "1234567890";
    int k = 3;
    string result = obj.findMaximumNum(str, k);
    cout << "Largest number after " << k << " swaps: " << result << endl;
    return 0;
}
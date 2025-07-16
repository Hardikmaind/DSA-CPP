#include <bits/stdc++.h>
using namespace std;

/*

Approach: Parity of Enumeration Elements
Intuition
According to the definition of a valid subsequence, we can observe that all elements at odd indices in the subsequence must have the same parity, and all elements at even indices must also have the same parity. Therefore, there are a total of four possible parity patterns for the subsequence:

All elements are even.
All elements are odd.
Elements at odd indices are odd, and elements at even indices are even.
Elements at odd indices are even, and elements at even indices are odd.
We can enumerate these four possibilities. For each one, we traverse the entire nums array and calculate the maximum length of a subsequence that fits the chosen pattern. While traversing, if the current number satisfies the required parity based on its position in the subsequence, we greedily increase the length by 1.
Finally, we return the maximum subsequence length across all possibilities.
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.maximumLength(nums) << endl; // Example usage
    return 0;
}
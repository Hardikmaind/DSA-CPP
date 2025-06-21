#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;
        for (auto &ch : word) {
            cnt[ch]++;
        }
        int res = word.size();
        for (auto &[_, a] : cnt) {
            int deleted = 0;
            for (auto &[_, b] : cnt) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            res = min(res, deleted);
        }
        return res;
    }
};

int main(){
    Solution sol;
    string word = "abcabc";
    int k = 1;
    cout << sol.minimumDeletions(word, k) << endl; // Example usage
    return 0;
}
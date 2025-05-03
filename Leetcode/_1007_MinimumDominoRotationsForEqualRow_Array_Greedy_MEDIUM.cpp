#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            vector<int> countTop(7, 0), countBottom(7, 0), same(7, 0);
            int n = tops.size();
            
            for (int i = 0; i < n; i++) {
                countTop[tops[i]]++;
                countBottom[bottoms[i]]++;
                if (tops[i] == bottoms[i]) same[tops[i]]++;
            }
            
            for (int i = 1; i <= 6; i++) {
                if (countTop[i] + countBottom[i] - same[i] == n) {
                    return min(n - countTop[i], n - countBottom[i]);
                }
            }
            return -1;
        }
    };
int main(){
    Solution sol;
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};
    cout << sol.minDominoRotations(tops, bottoms) << endl; // Output: 2
    return 0;
}    
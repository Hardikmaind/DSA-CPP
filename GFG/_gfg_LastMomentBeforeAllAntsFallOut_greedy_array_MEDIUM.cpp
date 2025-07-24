#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int num : left) {
            ans = max(ans, num);
        }
        for (int num : right) {
            ans = max(ans, n - num);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 10;
    vector<int> left = {1, 2, 3};
    vector<int> right = {7, 8, 9};
    cout << sol.getLastMoment(n, left, right) << endl; // Output: 7
    return 0;
}
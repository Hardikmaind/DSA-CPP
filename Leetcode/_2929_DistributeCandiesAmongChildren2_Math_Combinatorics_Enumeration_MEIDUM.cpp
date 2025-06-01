#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/distribute-candies-among-children-ii/solutions/6798482/distribute-candies-among-children-ii
class Solution {
public:
    long long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3 * cal(n - limit + 1) +
               3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};
int main(){
    Solution sol;
    int n = 5, limit = 2;
    cout << sol.distributeCandies(n, limit) << endl; // Example usage
    return 0;
}
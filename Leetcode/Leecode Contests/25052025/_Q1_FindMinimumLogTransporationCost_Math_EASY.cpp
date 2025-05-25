#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
         if(n < k && m < k) return 0;
        long cost = 0;

        if(n > k){
            long c1 = n-k;
            long c2 = n-c1;
            cost += c1 * c2;
        }
        if(m > k){
            long c1 = m-k;
            long c2 = m-c1;
            cost += c1 * c2;
        }
        return cost;
    }
};

int main(){
    Solution sol;
    int n = 6, m = 5, k = 5;
    cout << sol.minCuttingCost(n, m, k) << endl; // Example usage
    return 0;
}
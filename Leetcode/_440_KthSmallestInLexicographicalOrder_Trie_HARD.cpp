#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while (k > 0) {
            long step = 0, first = curr, last = curr + 1;
            // Calculate the step size
            while (first <= n) {
                step += min((long long)n + 1, (long long)last) - first;
                first *= 10;
                last *= 10;
            }
            // Move to the next branch
            if (k >= step) {
                k -= step;
                curr++;
            } 
            // Move down the current branch
            else {
                k--;
                curr *= 10;
            }
        }
        return (int) curr; 
    }
};
int main(){
    Solution obj;
    int n = 13, k = 2;
    int originalK = k;
    int result = obj.findKthNumber(n, k);
    cout << "The " << originalK << "th smallest number in lexicographical order from 1 to " << n << " is: " << result << endl;

    return 0;
}
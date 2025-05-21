#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count numbers <= mid in the multiplication table
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


int main(){
    Solution s;
    int m = 3, n = 3, k = 5;
    cout << s.kthSmallest(m, n, k) << endl; // Output: 3
    return 0;
}
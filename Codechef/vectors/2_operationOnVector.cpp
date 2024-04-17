#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
using namespace std;

long long mul(long long x, long long y) {
    return 1LL * x * y;
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n, val;
        cin >> n;
        
        vector<long long> nums(n);

        int min_val = 1e9, max_val = 0;

        for (int i = 0; i < n; i++) {
            cin >> val;
            nums[i] = val;  // Store the input values directly in nums
            max_val = max(max_val, val);
            min_val = min(min_val, val);
        }

        vector<long long> p_sum(n);
        partial_sum(nums.begin(), nums.end(), p_sum.begin());
        long long p_sum_product = accumulate(p_sum.begin(), p_sum.end(), 1LL, mul);
        cout << p_sum_product << " ";

        if (p_sum_product % min_val == 0 && p_sum_product % max_val == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

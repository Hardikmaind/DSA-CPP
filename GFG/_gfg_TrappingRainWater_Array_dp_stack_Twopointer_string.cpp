#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> leftmax(n), rightmax(n);

        // Initialize the first and last values
        leftmax[0] = arr[0];
        rightmax[n - 1] = arr[n - 1];

        // Fill leftmax array
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], arr[i]);
        }

        // Fill rightmax array
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], arr[i]);
        }

        // Calculate trapped water
        int trapwater = 0;
        for (int i = 0; i < n; i++) {
            int waterlvl = min(leftmax[i], rightmax[i]);
            trapwater += waterlvl - arr[i];
        }

        return trapwater;
    }
};

int main() {
    Solution s;

    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};

    cout << s.maxWater(arr);
}

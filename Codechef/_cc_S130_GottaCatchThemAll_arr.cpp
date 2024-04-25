#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y; // Input n, x, and y for each test case
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Input array elements
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(a[i] * x, y); // Calculate sum based on conditions
        }
        cout << sum << endl; // Output the sum for each test case
    }
    return 0;
}

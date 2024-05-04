#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];

        }
        sort(a, a + n);
        long long int o = 0;
        for (int i = 0; i < n; ++i) {
            o += abs(i - a[i]);
        }
        cout << o << endl;
    }
}



// 3
// 4
// 0 0 3 3
// 3
// 2 0 1
// 4
// 4 4 1 0
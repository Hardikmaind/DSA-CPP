#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        // Validate input
        if (N <= 0) {
            cout << "Invalid input\n";
            continue;
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            int ele;
            cin >> ele;
            // Check if the element is 2
            if (ele == 2) {
                count++;
            }
        }
        if (count%8==0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

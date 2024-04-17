#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector < int > v;
        for (int i = 0; i < N; i++) {
            int ele;
            cin >> ele;
            v.push_back(ele);;
        }
        bool marker = false;
        sort(v.begin(), v.end());
        for (int i = 1; i < N; i++) {
            if (v[i - 1] == v[i]) {

                marker = true;
            }
        }

        if (marker) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;

        }
    }

}
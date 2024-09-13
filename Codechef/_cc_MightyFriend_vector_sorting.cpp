#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        vector<int> motu, tomu;
        
        // Split the sequence into Motu's and Tomu's parts
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                motu.push_back(A[i]); // Motu picks elements from even indices
            } else {
                tomu.push_back(A[i]); // Tomu picks elements from odd indices
            }
        }
        
        // Sort Motu's elements in descending order and Tomu's elements in ascending order
        sort(motu.rbegin(), motu.rend());  // Largest first for Motu
        sort(tomu.begin(), tomu.end());    // Smallest first for Tomu
        
        // Perform up to K swaps
        int swaps = min(K, (int)min(motu.size(), tomu.size()));
        for (int i = 0; i < swaps; i++) {
            if (tomu[i] < motu[i]) {
                // Swap Tomu's smallest with Motu's largest
                swap(tomu[i], motu[i]);
            } else {
                // If no beneficial swap, break
                break;
            }
        }
        
        // Calculate the final scores
        int motu_score = 0, tomu_score = 0;
        
        for (int m : motu) {
            motu_score += m;
        }
        for (int t : tomu) {
            tomu_score += t;
        }
        
        // Check if Tomu wins
        if (tomu_score > motu_score) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}


// input output
// 2
// 6 0
// 1 1 1 1 1 1
// 5 1
// 2 4 6 3 4

// NO
// YES
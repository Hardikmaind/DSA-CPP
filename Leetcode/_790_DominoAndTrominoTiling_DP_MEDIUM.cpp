#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;
    
            vector<long long> arr(n + 1, 0);
            arr[0] = 1;
            arr[1] = 1;
            arr[2] = 2;
    
            int MOD = 1e9 + 7;
    
            for (int i = 3; i <= n; ++i) {
                arr[i] = (2 * arr[i - 1] % MOD + arr[i - 3]) % MOD;
            }
    
            return arr[n];
        }
    };

    

    int main(){
        Solution sol;
        int n = 3; // Example input
        cout << "Number of ways to tile a 2x" << n << " board: " << sol.numTilings(n) << endl;
        return 0;
    }


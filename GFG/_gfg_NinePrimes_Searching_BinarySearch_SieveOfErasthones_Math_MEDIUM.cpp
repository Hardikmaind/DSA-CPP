#include <bits/stdc++.h>
using namespace std;
/*

!Intuition
Numbers with exactly 9 divisors have a special property related to their prime factorization.

Key Insight:
A number has exactly 9 divisors if it falls into one of these forms:

p⁸ → (8+1 = 9 divisors)

p² × q² → (2+1)(2+1) = 9 divisors (where p and q are distinct primes)

Since p⁸ grows very rapidly (even 2⁸ = 256), for most practical constraints (like n ≤ 10¹⁸), the p² × q² case is more relevant.

!Approach
Generate all primes up to √n (since the maximum possible prime factor in p² × q² is √n).

Check for p⁴ ≤ n (since p² × q² ≤ n implies p⁴ ≤ n).

For each prime p, find primes q > p such that p² × q² ≤ n using binary search.

Count all valid (p, q) pairs where p² × q² ≤ n.

!Steps Breakdown:
Sieve of Eratosthenes: Generate all primes up to √n.

Check p⁴ case: If p⁴ ≤ n, count it.

Binary Search for q: For each prime p, find the largest prime q such that p² × q² ≤ n.

Sum up valid pairs: The number of valid q's for each p gives the count for p² × q² case.



*/
class Solution {
  public:
    const int N = 1e5+5;
  
    // Function to generate all primes up to n using Sieve of Eratosthenes
    vector<int> getPrimes(int n) {
        vector<bool> temp(n+5, true); // Sieve array
        for(int i = 2; i*i <= n; ++i) {
            if(temp[i]) {
                // Mark all multiples of i as non-prime
                for(int j = i*i; j <= n; j += i) {
                    temp[j] = false;
                }
            }
        }
        
        vector<int> ans;
        for(int i = 2; i <= n; ++i) {
            if(temp[i]) ans.push_back(i); // Collect primes
        }
        
        return ans;
    }

    int countNumbers(int n) {
        if(n < 36) return 0; // Smallest number with 9 divisors is 36 (2² × 3²)
        
        int sq = sqrt(n); // Maximum possible prime factor in p² × q²
        int ans = 0;
        
        // Generate all primes up to √n
        vector<int> allPrime = getPrimes(sq + 5);
        int sz = allPrime.size();
        
        bool flag = true;
        for(int i = 0; i < sz; ++i) {
            // Check p⁴ case (p⁸ is too big, so we consider p⁴ ≤ √n)
            if(flag) {
                long long int p4 = 1ll * allPrime[i] * allPrime[i] * allPrime[i] * allPrime[i];
                if(p4 <= sq) {
                    ans++; // p⁴ contributes 1 number (p⁸ is too large)
                } else {
                    flag = false; // No further primes will satisfy p⁴ ≤ n
                }
            }
            
            // Binary search to find the largest q such that p² × q² ≤ n
            int low = i + 1, high = sz - 1;
            int possible = i; // Default if no q found
            
            while(low <= high) {
                int mid = (low + high) / 2;
                long long num = 1ll * allPrime[i] * allPrime[mid];
                
                if(num <= sq) {
                    possible = mid;
                    low = mid + 1; // Try larger q
                } else {
                    high = mid - 1; // Try smaller q
                }
            }
            
            // Number of valid q's for current p
            int cnt = possible - i;
            ans += cnt;
        }
        
        return ans;
    }
};


/*
Complexity Analysis
Time Complexity:

Sieve of Eratosthenes: O(√n log log √n)

Binary Search per prime: O(π(√n) log π(√n)) (where π(x) is the prime-counting function)

Total: O(√n log log √n + π(√n) log π(√n)) ≈ O(√n log n)

Space Complexity: O(√n) (for storing primes)
*/


int main(){
    Solution sol;
    int n=100; // Example input
    cout << sol.countNumbers(n) << endl; // Output the count of numbers with exactly
    return 0; // 9 divisors
}
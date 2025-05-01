#include <bits/stdc++.h>
using namespace std;

//! tc is O(n^2) and sc is O(n) for the auxiliary space used by the recursion stack
/*
This approach is inefficient and error-prone for large n, due to:
Redundant recursive calls
Integer overflows
Stack overflow risk
Not suitable for competitive programming.
*/

class Solution2
{
public:
    long long fact(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return n * fact(n - 1);
    }

    long long nCr(int n, int r)
    {
        return fact(n) / (fact(r) * fact(n - r));
    }

    vector<int> nthRowOfPascalTriangle(int n)
    {
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back((int)nCr(n - 1, i));
        }
        return res;
    }
};

//! TC is O(n⋅logMOD) and sc is O(n).log MOD ≈ 30 is constant time for practical purposes

class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        const int MOD = 1e9 + 7;
        vector<int> res;
        long long val = 1;
        res.push_back(1); // nC0 is always 1

        for (int i = 1; i < n; i++)
        {                              // changed from i <= n to i < n
            val = val * (n - i) % MOD; // changed from (n - i + 1)
            val = val * modInverse(i, MOD) % MOD;
            res.push_back((int)val);
        }

        return res;
    }

    // Modular inverse using Fermat’s Little Theorem since MOD is prime
    long long modInverse(int a, int mod)
    {
        return power(a, mod - 2, mod);
    }

    long long power(long long x, long long y, int mod)
    {
        long long res = 1;
        x = x % mod;
        while (y > 0)
        {
            if (y & 1)
                res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }
};

//! Final Efficient Code — O(n) Time and Space Complexity
/*
Precompute factorials: O(n)
Precompute inverse factorials: O(n)
Build result vector: O(n)
Each modInverse using binary exponentiation: O(log MOD)
*/

class Solution3
{
public:
    const int MOD = 1e9 + 7;

    vector<int> nthRowOfPascalTriangle(int n)
    {
        vector<long long> fact(n);
        vector<long long> invFact(n);

        // Precompute factorials modulo MOD
        fact[0] = 1;
        for (int i = 1; i < n; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // Precompute inverse factorials modulo MOD using Fermat's little theorem
        invFact[n - 1] = modInverse(fact[n - 1], MOD);
        for (int i = n - 2; i >= 0; i--)
        {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        // Generate nth row (1-based: actually (n-1)th row in 0-based indexing)
        vector<int> res;
        for (int r = 0; r < n; r++)
        {
            long long val = fact[n - 1] * invFact[r] % MOD;
            val = val * invFact[n - 1 - r] % MOD;
            res.push_back((int)val);
        }

        return res;
    }

    long long modInverse(long long a, int mod)
    {
        return power(a, mod - 2, mod);
    }

    long long power(long long x, long long y, int mod)
    {
        long long res = 1;
        x = x % mod;
        while (y > 0)
        {
            if (y & 1)
                res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }
};

int main()
{
    int n = 4; // Example input
    Solution sol;
    vector<int> result = sol.nthRowOfPascalTriangle(n);
    for (int i : result)
    {
        cout << i << " ";
    }

    Solution2 sol2;
    vector<int> result2 = sol2.nthRowOfPascalTriangle(n);
    cout << endl;
    for (int i : result2)
    {
        cout << i << " ";
    }

    cout << endl;
    Solution3 sol3;
    vector<int> result3 = sol3.nthRowOfPascalTriangle(n);
    for (int i : result3)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
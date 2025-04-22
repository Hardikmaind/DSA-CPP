#include <iostream>
#include <cmath>
using namespace std;

//* --- Method 1: Binet's Formula (O(1), Approximate for large n) ---
long long fibonacci_binet(int n) {
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    return round(pow(phi, n) / sqrt5);
}

//* --- Method 2: Fast Doubling (O(log n), Exact) ---
pair<long long, long long> fib_helper(int n) {
    if (n == 0) return {0, 1};
    auto [a, b] = fib_helper(n >> 1);
    long long c = a * (2 * b - a);
    long long d = a * a + b * b;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

long long fibonacci_fast_doubling(int n) {
    return fib_helper(n).first;
}

//* --- Method 3: Matrix Exponentiation (O(log n), Exact) ---
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long long F[2][2], int n) {
    if (n == 0 || n == 1) return;
    long long M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}

long long fibonacci_matrix(int n) {
    if (n == 0) return 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

//* --- Main Function ---
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") using Binet's Formula      = " << fibonacci_binet(n) << " (approx)" << endl;
    cout << "Fibonacci(" << n << ") using Fast Doubling         = " << fibonacci_fast_doubling(n) << " (exact)" << endl;
    cout << "Fibonacci(" << n << ") using Matrix Exponentiation = " << fibonacci_matrix(n) << " (exact)" << endl;

    return 0;
}

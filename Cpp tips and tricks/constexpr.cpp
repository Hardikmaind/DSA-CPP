// File 1: constexpr_examples.cpp
#include <iostream>
#include <array>

// A simple constexpr function to compute square at compile time
constexpr int square(int x) {
    return x * x;
}

// Recursive constexpr function for factorial (C++14 and later)
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

// A struct with constexpr constructor and member function
struct Point {
    int x, y;
    constexpr Point(int a, int b) : x(a), y(b) {}
    constexpr int sum() const { return x + y; }
};

int main() {
    // All computed at compile time
    constexpr int val = square(5);
    constexpr int fact = factorial(5);
    constexpr Point p(3, 4);
    constexpr int point_sum = p.sum();

    // constexpr used to define array size
    std::array<int, factorial(4)> arr; // array of size 24

    std::cout << "Square: " << val << "\n";
    std::cout << "Factorial: " << fact << "\n";
    std::cout << "Point Sum: " << point_sum << "\n";
}

// File 3: consteval_examples.cpp
#include <iostream>

// consteval forces the function to be evaluated at compile time (C++20)
consteval int triple(int x) {
    return 3 * x;
}

// Another example: this function can never be used at runtime
consteval int compileTimeOnly() {
    return 123;
}

int main() {
    // Valid: all are constexpr values known at compile time
    constexpr int t = triple(4);
    constexpr int v = compileTimeOnly();

    std::cout << "Triple: " << t << "\n";
    std::cout << "Compile-time consteval value: " << v << "\n";

    // Uncommenting below will cause compile error: x is not a constant expression
    // int x = 10;
    // int r = triple(x); // ERROR: consteval requires compile-time value
}

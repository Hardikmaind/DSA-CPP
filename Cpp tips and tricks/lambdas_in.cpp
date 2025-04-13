
// File 2: lambda_examples.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Basic lambda function
    auto greet = []() { std::cout << "Hello from lambda!\n"; };
    greet();

    // Lambda with parameters and return type
    auto add = [](int a, int b) -> int { return a + b; };
    std::cout << "Add: " << add(2, 3) << "\n";

    // Capture by value (=) and by reference (&)
    int x = 10, y = 20;
    auto byVal = [=]() { std::cout << "By Value: " << x << ", " << y << "\n"; }; // x and y are copied
    auto byRef = [&]() { x++; y++; }; // x and y are modified directly
    byRef(); byVal();

    // Mutable lambda allows modifying captured by-value variables inside lambda (but only inside)
    auto mutableLambda = [x]() mutable { x += 5; std::cout << "Mutable x: " << x << "\n"; }; // does not change outer x
    mutableLambda();

    // Generic lambda (auto type deduction, C++14+)
    auto printer = [](auto val) { std::cout << "Value: " << val << "\n"; };
    printer(42);
    printer(3.14);
    printer("Hello");

    // Lambda used in STL algorithm (for_each)
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << " ";
    });
    std::cout << "\n";

    // Lambda returning another lambda (lambda factory)
    auto make_multiplier = [](int factor) {
        return [factor](int x) { return factor * x; };
    };
    auto times3 = make_multiplier(3);
    std::cout << "Times3 of 10: " << times3(10) << "\n";
}


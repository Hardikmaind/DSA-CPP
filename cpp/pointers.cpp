#include <iostream>



// Using Pointers:
// This approach involves passing pointers to the integers that need to be swapped.
// Inside the function, you dereference the pointers to access and modify the actual values in memory.
void swapIntegers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Using References:
// This approach uses references directly in the function parameters, eliminating the need for explicit dereferencing.
// It's a cleaner and more straightforward way to achieve swapping in C++.

void swapIntegers2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    swapIntegers(&x, &y);

    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;



    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    swapIntegers2(x, y);

    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;


    return 0;
}

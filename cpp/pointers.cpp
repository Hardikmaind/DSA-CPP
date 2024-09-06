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

// In the context of int &a in the function swapIntegers2(int &a, int &b), a is a reference, not a value or an address. Let's break down what happens when you declare a reference like this.
// What does int &a store?
// int &a is a reference to an integer, which means that a is just another name (alias) for an existing integer variable, not a separate variable itself.
// When you pass a variable like x (in the main() function) to swapIntegers2, the reference a is bound to x. This means that a refers to the same memory location as x — any operation on a directly affects x.
// So, int &a stores a reference to x, allowing you to manipulate x through a.
void swapIntegers2(int &a, int &b) {
    int temp = a;  // Step 1: 'a' refers to the original 'x', so temp stores the value of 'x'
    a = b;         // Step 2: 'b' refers to the original 'y', so 'x' now gets the value of 'y'
    b = temp;      // Step 3: 'y' gets the old value of 'x' (stored in 'temp')
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





    std::cout << "============  reference operator and address-of operator is different ==================" << std::endl;

    int z = 42;

    // Address-of operator: get the memory address of 'z'
    int* ptr = &z;  // 'ptr' stores the memory address of 'z'       //HERE & IS USED AS ADDRESS OF OPERATOR

    // Reference operator: create an alias (reference) to 'z'
    int& ref = z;   // 'ref' is a reference to 'z'                   //HERE ALSO & IS USED BUT IT IS NOT ADDRESS OF OPERATOR

    // Access the value of 'z' through pointer dereferencing and reference
    std::cout << *ptr << std::endl;  // Prints 42 (dereferencing 'ptr')
    std::cout << ref << std::endl;   // Prints 42 (accessing through reference)

    

    return 0;
}

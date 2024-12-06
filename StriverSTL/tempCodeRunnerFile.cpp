nt x = 42;

    // Address-of operator: get the memory address of 'x'
    int* ptr = &x;  // 'ptr' stores the memory address of 'x'

    // Reference operator: create an alias (reference) to 'x'
    int& ref = x;   // 'ref' is a reference to 'x'

    // Access the value of 'x' through pointer dereferencing and reference
    std::cout << *ptr << std::endl;  // Prints 42 (dereferencing 'ptr')
    std::cout << ref << std::endl;   // Prints 42 (accessing through reference)
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr;
    int number;

    std::cout << "Enter integers (press Ctrl+D to stop): " << std::endl;

    // Read integers from standard input until EOF (Ctrl+D in Unix, Ctrl+Z in Windows)
    while (std::cin >> number) {
        arr.push_back(number);
    }

    std::cout << "You entered: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

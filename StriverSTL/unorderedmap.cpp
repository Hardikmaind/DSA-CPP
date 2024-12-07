#include <unordered_map>
#include <vector>
#include <iostream>

int main() {
    std::unordered_map<int, int> m;
    std::vector<int> citations = {4, 3, 4, 2, 3, 4}; // Example data

    for (int x : citations) {
        m[x]++; // Directly increment the value
    }

    // Print the contents of the map
    for (const auto& [key, value] : m) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    return 0;
}

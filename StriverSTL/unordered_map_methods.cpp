#include <iostream>
#include <unordered_map>
#include <string>

void printMap(const std::unordered_map<std::string, int>& map) {
    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::unordered_map<std::string, int> myMap;

    // 1. Insertion and modification
    myMap.insert({"apple", 5});
    myMap.emplace("banana", 3);
    myMap["cherry"] = 7;
    std::cout << "After insertion:" << std::endl;
    printMap(myMap);

    // Using at()
    std::cout << "Value of 'banana' using at(): " << myMap.at("banana") << std::endl;

    // 2. Lookup
    auto it = myMap.find("apple");
    if (it != myMap.end()) {
        std::cout << "Found 'apple' with value: " << it->second << std::endl;
    }

    std::cout << "Count of 'banana': " << myMap.count("banana") << std::endl;

    // C++20 feature: contains()
    // Uncomment if your compiler supports C++20
    // if (myMap.contains("cherry")) {
    //     std::cout << "Map contains 'cherry'" << std::endl;
    // }

    // 3. Erasure
    myMap.erase("banana");
    std::cout << "After erasing 'banana':" << std::endl;
    printMap(myMap);

    // 4. Size and capacity
    std::cout << "Is empty: " << (myMap.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << myMap.size() << std::endl;
    std::cout << "Max size: " << myMap.max_size() << std::endl;

    // 5. Buckets
    std::cout << "Bucket count: " << myMap.bucket_count() << std::endl;
    std::cout << "Max bucket count: " << myMap.max_bucket_count() << std::endl;
    std::cout << "Bucket size of 'apple': " << myMap.bucket_size(myMap.bucket("apple")) << std::endl;
    std::cout << "Bucket of 'apple': " << myMap.bucket("apple") << std::endl;

    // 6. Hash policy
    std::cout << "Load factor: " << myMap.load_factor() << std::endl;
    std::cout << "Max load factor: " << myMap.max_load_factor() << std::endl;
    myMap.rehash(20);
    myMap.reserve(30);

    // 7. Observers
    auto hash_fn = myMap.hash_function();
    auto key_eq_fn = myMap.key_eq();
    std::cout << "Hash of 'apple': " << hash_fn("apple") << std::endl;
    std::cout << "Are 'apple' and 'apple' equal: " << (key_eq_fn("apple", "apple") ? "Yes" : "No") << std::endl;

    // 8. Iterators
    std::cout << "Iterating through the map:" << std::endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // 9. Other
    std::unordered_map<std::string, int> otherMap{{"date", 10}, {"elderberry", 8}};
    myMap.swap(otherMap);
    std::cout << "After swapping with another map:" << std::endl;
    printMap(myMap);

    // C++17 feature: merge()
    // Uncomment if your compiler supports C++17
    // myMap.merge(otherMap);
    // std::cout << "After merging:" << std::endl;
    // printMap(myMap);

    return 0;
}
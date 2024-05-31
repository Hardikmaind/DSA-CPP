#include <iostream>
#include <set>
int main() {
    std::multiset<int> myMultiset;

    // Insert elements into the multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10);
    myMultiset.insert(30);
    myMultiset.insert(20);
    myMultiset.insert(10);

    // Output the elements
    std::cout << "Multiset elements: ";
    for (const int &elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Counting the frequency of an element
    int num = 10;
    std::cout << "Count of " << num << " : " << myMultiset.count(num) << std::endl;

    // Finding an element
    auto it = myMultiset.find(20);
    if (it != myMultiset.end()) {
        std::cout << "Element 20 found in the multiset." << std::endl;
    } else {
        std::cout << "Element 20 not found in the multiset." << std::endl;
    }

    // Lower and Upper bounds
    auto lower = myMultiset.lower_bound(10);
    auto upper = myMultiset.upper_bound(10);
    std::cout << "Lower bound of 10: " << *lower << std::endl;
    std::cout << "Upper bound of 10: " << *upper << std::endl;

    // Equal range
    auto range = myMultiset.equal_range(10);
    std::cout << "Elements in the range of 10: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Removing a single instance of an element
    myMultiset.erase(myMultiset.find(10));
    std::cout << "Multiset elements after removing one instance of 10: ";
    for (const int &elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Removing all instances of an element
    myMultiset.erase(10);
    std::cout << "Multiset elements after removing all instances of 10: ";
    for (const int &elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}


// Explanation of Additional Methods:
// Find: Used to find an element. It returns an iterator to the first occurrence of the element or end() if the element is not found.
// Lower Bound: Returns an iterator to the first element that is not less than the specified value.
// Upper Bound: Returns an iterator to the first element that is greater than the specified value.
// Equal Range: Returns a pair of iterators that represent the range of elements equal to the specified value.
// Erase (Single Instance): You can use an iterator to remove a single instance of an element.

// Equal Range: The equal_range method returns a std::pair of iterators. In this pair, the first element (range.first) is the iterator to the first element that is equal to the specified value, and the second element (range.second) is the iterator to one past the last element that is equal to the specified value.
// Iteration: In the for loop, the correct comparison is it != range.second instead of it != range.last.
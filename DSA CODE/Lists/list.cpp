
// #include<bits/stdc++.h> is not a standard C++ header file. It's a non-standard header that is commonly used in competitive programming environments like Codeforces and some online judges. This header is provided by certain compilers (like GCC and MinGW) and includes a large set of standard C++ headers.

// The purpose of #include<bits/stdc++.h> is to simplify the inclusion of common standard headers like <iostream>, <vector>, <string>, <algorithm>, <cmath>, <cstdio>, <cstdlib>, <ctime>, <deque>, <queue>, <set>, <map>, <stack>, <bitset>, <list>, <functional>, <numeric>, <utility>, <iomanip>, <sstream>, <fstream>, <cassert>, <limits>, <exception>, <stdexcept>, <climits>, <cstddef>, <cstdint>, <cstring>, <cwchar>, <cwctype>, <cctype>, <ctime>, <cstdlib>, <cstdarg>, <clocale>, <cuchar>, <cuchar>, <cuchar>, and <ctime>.

// While convenient, it's worth noting that using #include<bits/stdc++.h> is not standard practice outside of competitive programming or quick prototyping scenarios. In production code or larger projects, it's generally recommended to include only the specific headers you need, as including unnecessary headers can lead to increased compile times and potential naming conflicts.









#include <iostream>
#include <list>
// #include <bits/stdc++.h>


using namespace std;

int main() {
    // Declaration and initialization of a list
    list<int> myList = {1, 2, 3, 4, 5};

    // Adding elements to the list
    myList.push_back(6);    // Adds 6 at the end of the list
    myList.push_front(0);   // Adds 0 at the beginning of the list

    // Displaying the elements of the list
    cout << "List elements:";
    for (const auto& elem : myList) {
        cout << " " << elem;
    }
    cout << endl;

    // Accessing elements by index (not directly supported in lists, but can be done using iterators)
    list<int>::iterator it = myList.begin();
    advance(it, 3); // Move iterator to the 4th element (index 3)
    cout << "Element at index 3: " << *it << endl;

    // Removing elements from the list
    myList.pop_back();      // Removes the last element (6)
    myList.pop_front();     // Removes the first element (0)

    // Removing specific elements
    myList.remove(3);       // Removes all occurrences of value 3

    // Displaying the modified list
    cout << "Modified list:";
    for (const auto& elem : myList) {
        cout << " " << elem;
    }
    cout << endl;

    // Other useful methods:
    cout << "Size of the list: " << myList.size() << endl;  // Size of the list
    cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << endl;  // Check if list is empty

    // Clearing the list
    myList.clear();

    cout << "Is the list empty after clearing? " << (myList.empty() ? "Yes" : "No") << endl;


    return 0;
}

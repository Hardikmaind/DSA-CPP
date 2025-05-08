#include <iostream>
using namespace std;


class Counter {
    public:
        static int count;
    
        static void increment() {
            ++count;
        }
    
        void printCount() {
            cout << "Count is: " << count << endl;
        }
    };
    
    // Define static variable
    int Counter::count = 0;
    
    int main() {
        Counter a, b;
        Counter::increment();  // Static function called using class name       .increaments to 1
        a.increment();         // Valid, but not recommended                    .increments to 2
        b.increment();                                             //           .increments to 3    
    
        a.printCount();  // Output: Count is: 3
        b.printCount();  // Output: Count is: 3
    }
    


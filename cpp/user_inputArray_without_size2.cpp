#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> arr;
    string inputLine;
    
    // Read the entire line of input
    cout << "Enter integers separated by spaces: ";
    getline(cin, inputLine);
    
    // Create a stringstream from the input line
    istringstream stream(inputLine);
    int number;

    // Parse the integers from the stringstream
    while (stream >> number) {
        arr.push_back(number);
    }

    // Output the integers to verify they were read correctly
    cout << "You entered: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

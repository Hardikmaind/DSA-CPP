#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> myBitset; // 8-bit bitset, initially all bits are 0

    // Setting bits
    myBitset.set(1);
    myBitset.set(3);
    myBitset.set(7);
    std::cout << "After setting bits: " << myBitset << std::endl; // Output: 10001001

    // Resetting bits
    myBitset.reset(3);
    std::cout << "After resetting bit 3: " << myBitset << std::endl; // Output: 10000001

    // Flipping bits
    myBitset.flip(0);
    std::cout << "After flipping bit 0: " << myBitset << std::endl; // Output: 10000000

    // Counting bits
    std::cout << "Number of set bits: " << myBitset.count() << std::endl; // Output: 1

    // Accessing bits
    std::cout << "Bit at position 7: " << myBitset[7] << std::endl; // Output: 1

    // Checking if any, all, or none bits are set
    std::cout << "Any bits set: " << myBitset.any() << std::endl; // Output: 1
    std::cout << "All bits set: " << myBitset.all() << std::endl; // Output: 0
    std::cout << "No bits set: " << myBitset.none() << std::endl; // Output: 0

    // Converting to string
    std::string bitString = myBitset.to_string();
    std::cout << "Bitset as string: " << bitString << std::endl; // Output: 10000000

    // Converting to unsigned long
    unsigned long bitLong = myBitset.to_ulong();
    std::cout << "Bitset as unsigned long: " << bitLong << std::endl; // Output: 128

    return 0;
}







// Methods of std::bitset
// Here is a list of the primary methods available in std::bitset, along with a brief description of each:

// Constructor Methods:

// bitset<N>(): Default constructor. Initializes all bits to 0.
// bitset<N>(unsigned long val): Initializes the bitset with the binary representation of val.
// bitset<N>(const std::string& str, std::size_t pos = 0, std::size_t n = std::string::npos, char zero = '0', char one = '1'): Initializes the bitset from a string.
// Access Methods:

// bool operator[](std::size_t pos) const: Returns the value of the bit at position pos.
// bool test(std::size_t pos) const: Returns the value of the bit at position pos, with bounds checking.
// Modification Methods:

// bitset<N>& set(): Sets all bits to 1.
// bitset<N>& set(std::size_t pos, bool value = true): Sets the bit at position pos to value.
// bitset<N>& reset(): Resets all bits to 0.
// bitset<N>& reset(std::size_t pos): Resets the bit at position pos to 0.
// bitset<N>& flip(): Flips all the bits (0 to 1 and 1 to 0).
// bitset<N>& flip(std::size_t pos): Flips the bit at position pos.
// Size and Count Methods:

// std::size_t size() const: Returns the number of bits in the bitset.
// std::size_t count() const: Returns the number of bits that are set to 1.
// Boolean Methods:

// bool all() const: Returns true if all bits are set to 1.
// bool any() const: Returns true if any bit is set to 1.
// bool none() const: Returns true if none of the bits are set to 1.
// Conversion Methods:

// unsigned long to_ulong() const: Converts the bitset to an unsigned long.
// unsigned long long to_ullong() const: Converts the bitset to an unsigned long long.
// std::string to_string(char zero = '0', char one = '1') const: Converts the bitset to a string representation.
// Comparison Operators:

// bool operator==(const bitset<N>& rhs) const: Equality comparison.
// bool operator!=(const bitset<N>& rhs) const: Inequality comparison.
// Bitwise Operators:

// bitset<N> operator& (const bitset<N>& rhs) const: Bitwise AND.
// bitset<N> operator| (const bitset<N>& rhs) const: Bitwise OR.
// bitset<N> operator^ (const bitset<N>& rhs) const: Bitwise XOR.
// bitset<N> operator~ () const: Bitwise NOT.
// bitset<N>& operator&= (const bitset<N>& rhs): Bitwise AND assignment.
// bitset<N>& operator|= (const bitset<N>& rhs): Bitwise OR assignment.
// bitset<N>& operator^= (const bitset<N>& rhs): Bitwise XOR assignment.
// bitset<N> operator<< (std::size_t pos) const: Left shift.
// bitset<N> operator>> (std::size_t pos) const: Right shift.
// bitset<N>& operator<<= (std::size_t pos): Left shift assignment.
// bitset<N>& operator>>= (std::size_t pos): Right shift assignment.
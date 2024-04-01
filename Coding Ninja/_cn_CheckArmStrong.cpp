#include <iostream>
#include <cmath>
using namespace std;

void demo(); // Forward declaration

bool checkArmstrong(int n) {
    int noofDig =(int) log10(n) + 1;
    int m = n;
    int result = 0;
    while (m > 0) {
        int temp = m % 10;
        result +=(int) pow(temp, noofDig);
        m = m / 10;
    }
    return result == n;
}

int main() {
    int n = 370;
    bool result=checkArmstrong(n);
    cout<<boolalpha<<result<<endl;          //this boolalpha is used to print true or false instead of 1 or 0
  
    demo(); // Call the demo function
    return 0;
}

void demo() {
    cout << "hello world";
}

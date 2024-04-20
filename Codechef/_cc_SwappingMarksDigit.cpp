#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int reverseno(int no) {
    int rev = 0;
    while (no > 0) {
        rev = rev * 10 + no % 10;
        no /= 10;
    }
    return rev;
}
int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        int noA = reverseno(A);                 //here i cant do like reverseno(&A) because we need A in the below if condition and ..if passed as a reference then it will change the value of A (original value will get change then we will not get out answer correct)
        int noB = reverseno(B); 

        if (A > B || noA > B || A > noB || noA > noB) {
            cout << "Yes\n";
        } else {

            cout << "No\n";


        }
    }

    return 0;
}

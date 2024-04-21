#include <iostream>
using namespace std;

#define f1(i,n) for(int i=1;i<=n;i++)

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    f1(i, N) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


// In this code, we've defined the macro f1(i,n) to create a loop from 1 to n. Inside the main() function, we use cout and cin from the std namespace without explicitly writing std:: before them. This is made possible by the using namespace std; directive at the beginning of the code.








// Good point! In the code snippet I provided earlier, I used int N; to define the variable for input but didn't define int i separately because it's part of the macro f1(i,n).

// When you use the macro f1(i,n), it automatically defines int i within the loop. Here's what the macro does:


// #define f1(i,n) for(int i=1;i<=n;i++)
// When you write f1(i, N) { ... }, the preprocessor replaces f1(i, N) with for(int i=1; i<=N; i++) { ... }. Therefore, int i is effectively defined within the loop due to the macro expansion.

// Here's how the loop looks after macro expansion:

// for(int i=1; i<=N; i++) {
//     cout << i << " ";
// }
// So, there's no need to separately define int i outside of the loop when using the f1(i,n) macro.
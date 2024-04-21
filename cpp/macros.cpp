#include <iostream>
using namespace std;

#define f1(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int N;
    cout << "this is macro f1 Enter a number: ";
    cin >> N;

    f1(i, N) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

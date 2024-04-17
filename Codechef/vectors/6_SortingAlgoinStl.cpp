#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Write your code here
    int ele;
    cin >> ele;
    vector<int> arr;
    for (int i = 0; i < ele; i++)
    {
        int no;
        cin >> no;
        arr.push_back(no);
    }
    sort(arr.begin(), arr.end());
    for (int &x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

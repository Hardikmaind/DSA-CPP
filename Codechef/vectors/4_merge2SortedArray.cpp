// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int l1, l2;
    cin >> l1 >> l2;

    vector<int> v1(l1);
    vector<int> v2(l2);
    vector<int> v(l1 + l2);

    for (int i = 0; i < l1; i++)
    {
        cin >> v1[i]; // Use indexing to assign elements to v1
    }
    for (int i = 0; i < l2; i++)
    {
        cin >> v2[i]; // Use indexing to assign elements to v2
    }

    bool sorted1 = is_sorted(v1.begin(), v1.end());
    bool sorted2 = is_sorted(v2.begin(), v2.end());

    if (sorted1 && sorted2)
    {
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin()); // Use v.begin() to specify the output range
        sort(v.begin(), v.end());                                     // Add parentheses to sort function call
        for (int x : v)
        { // Use value iteration (not reference) since v is a vector of int, not int&
            cout << x << " ";
        }
    }
    else
    {
        if (l1 > l2)
        {
            for (int i = v1.size() - 1; i >= 0; i--)
            { // Use value iteration (not reference) since v1 is a vector of int, not int&
                cout << v1[i] << " ";
            }
        }
        else
        {
            for (int i = v2.size() - 1; i >= 0; i--)
            { // Use value iteration (not reference) since v1 is a vector of int, not int&
                cout << v2[i] << " ";
            }
        }
    }

    return 0;
}


// input
// 5 4
// 4 7 6 9 10
// 4 5 7 8

// output
// 10 9 6 7 4
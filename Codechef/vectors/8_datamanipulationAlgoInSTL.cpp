#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> v(N);
    iota(v.begin(), v.end(), x);            //to use iota we need to include <numeric>
    reverse(v.begin(), v.end());

    // for (auto &num : v) {
    //     cout << num << " ";
    // }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}



// 5 4
// 8 7 6 5 4 
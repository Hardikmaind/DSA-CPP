#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, S, L, U;
    cin >> N >> S >> L >> U;
    vector<int> v(N); // Corrected: Creating a vector of size N




// vector<int> v;: This line declares an empty vector v.
// for(int i=0;i<v.size();i++): Here, v.size() is initially zero because v is empty. So, the loop condition i<v.size() is never true, and the loop body won't execute.
// cin>>v.push_back(ele);: This line combines two operations, reading input into ele and pushing ele into the vector v. However, the push_back function doesn't return anything, so cin won't work as expected here.

    //why below is wrong. above i have written the reason

//   int N,S,L,U;
//   cin>>N>>S>>L>>U;
//   vector<int>v;
//   for(int i=0;i<v.size();i++){
//       int ele;
//       cin>>v.push_back(ele);
//   }




    
    // Reading elements into the vector
    for (int i = 0; i < N; i++) {
        cin >> v[i]; // Corrected: Reading elements and pushing into the vector
    }
    
    sort(v.begin(), v.end()); // Corrected: Sorting the vector
    
    bool it = binary_search(v.begin(), v.end(), S);
    auto it2 = lower_bound(v.begin(), v.end(), L);
    auto it3 = upper_bound(v.begin(), v.end(), U);
    
    if (it) {
        cout << "YES ";
    } else {
        cout << "NO ";
    }
    
    // Printing the index where L is found and the index after U
    cout << *it2  << " " << *it3 << endl;
    
    return 0;
}

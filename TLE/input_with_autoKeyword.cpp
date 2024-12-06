#include <bits/stdc++.h>
using namespace std;
int main(){

    //! TAKING INPUT IN AN ARRAY USING AUTO KEYWORD    
    int ar[5];
    // ==========GARBAGE VALUES ARE GETTING PRINTED
    for(auto &x:ar){
        cout<<x<<endl;
    }
    // ========== INPUT IS BEING TAKEN
    for(auto &x:ar){
        cin>>x;         //so basically x is getting overwrittern. from garbage value to the value entered by the user
    }
    // ========== ENTERD VALUE IS BEING PRINTED
    for(auto &x:ar){
        cout<<x<<endl;
    }

}

/*
Iterates over all elements of the array ar.
auto &x:
auto: Automatically deduces the type, which is int for elements of ar.
&: Means x is a reference to each element of the array, allowing modifications to ar through x.
Without the &, a copy of each element would be used, and modifications wouldn't affect the original array.
*/
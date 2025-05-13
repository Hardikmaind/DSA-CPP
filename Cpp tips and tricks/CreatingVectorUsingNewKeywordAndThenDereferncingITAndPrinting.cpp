#include <bits/stdc++.h>
using namespace std;


//! I have below returned the pointer to the vector<int> ,which I have created using new keyword.
vector<int>* newVector(int size) {
    return new vector<int>(size);           // since this is returning the pointer , I will have to dereference it to access the vector<int> object in the main function
}

int main(){

    auto res=newVector(5);
    for(int i=0;i<5;i++){
        (*res)[i]=i;        //yaha initialize kiya and then niche print kiya, wohi
        cout<<(*res)[i]<<" ";
    }

    return 0;
}
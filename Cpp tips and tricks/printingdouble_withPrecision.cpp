#include <bits/stdc++.h>
using namespace std;

int main(){
    auto res=[](){cout<<"Hello world"<<endl;};
    res();
    auto res2=[](){return 1;};
    cout<<res2()<<endl;

    auto res3=[]()->double{return 1.0;};
    
    cout<<(double)res3()<<endl;         //here cout trims the zeros. to print the decimal i have to use the fixed and setprecision() method in the cout like below

    cout << fixed << setprecision(1) << res3() <<" hello world"<< endl; // Output: 1.0. here the precision is set to 1 decimal place and the fixed is used to trim the zeros. and then i can print the decimal value. then i print the hello world string. 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int fruitsIntoBaskets(vector<int>&arr){
    int b1=0,b2=0,l=0,r=0,maxfruits=0,n=arr.size();
   
    unordered_map<int,int>map;
    while(r<n){
        map[arr[r]]++;

        while (map.size() > 2) {
            map[arr[l]]--;
            if (map[arr[l]] == 0)
                map.erase(arr[l]);          //! yes we also have to erase it, unlike in java c++ does not remove keys with zero values
            l++;
        }

        maxfruits = max(maxfruits, r - l + 1);
        r++;

        
        
    }
    return maxfruits;
}

/*
int demo(){
    return 1;
}
int demo3(){
    cout<<"hello 3"<<endl;
    return 3;
}
void demo2(){
    cout<<"hello 2"<<endl;
}
*/
int main(){
    vector<int> arr={3,3,3,1,2,1,1,2,3,3,4};
    cout<<fruitsIntoBaskets(arr)<<endl;
    /*
    cout<<demo()<<endl;
    // cout<<demo2()<<endl;
    demo2();
    cout<<demo3()<<endl;
    */
return 0;
}
#include <bits/stdc++.h>
using namespace std;

//! TC: O(n) + O(2n) = O(n)
//! SC: O(2n) = O(n) for the map
//* THIS IS THE OPTIMISEC SOLUTION
int fruitsIntoBaskets(vector<int>&arr){
    int l=0,r=0,maxfruits=0,n=arr.size();
   
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


//* THIS BELOW IS THE BRUTE FORCE SOLUTION
//! this is the brute force solution tc is O(n^2) {ignore the adding in the set which is logN, but N=2, so ignore}. and sc is also 1 ignore since set size is only 2.
int fruitsIntoBaskets2(vector<int>&arr){
    int maxlen=0;
    for(int i=0;i<arr.size();i++){
        unordered_set<int>set;
        for(int j=i;j<arr.size();j++){
            set.insert(arr[j]);
            if(set.size()<=2){
                maxlen=max(maxlen,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlen;
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
    cout<<fruitsIntoBaskets2(arr)<<endl;
    /*
    cout<<demo()<<endl;
    // cout<<demo2()<<endl;
    demo2();
    cout<<demo3()<<endl;
    */
return 0;
}
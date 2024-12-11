#include <bits/stdc++.h>
using namespace std;
// FIND LOWER BOUND of m means => Smallest Index Such that "arr[index]>=m".
int findLowerbound(vector<int>& arr,int &m){
    int n=arr.size();           //! If no answer found always return the hypothetical answer
    int l=0,r=arr.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]>=m){            //agar beech wala element m se jyada hain toh possible hain ki usse kam wale index bhi m se jyada honge..therefore removed the right search space. and also possible that ki wohi lower bound ho
            n=mid;
            r=mid-1;

        }else{
            l=mid+1;
        }
    }
    return n;
}

int main(){
    vector<int> arr={1,2,3,3,5,6,6,6,8,8,10,10,11};
    int m=7;
    int lowerbound=findLowerbound(arr,m);
    cout<<lowerbound<<endl;


    //! default method in the cpp

    //* lower_bound=>Iterator to the first element of the range [first, last) not ordered before value, or last if no such element is found.
    int lowerBound=lower_bound(arr.begin(),arr.end(),6)-arr.begin(); //! ans is 5
    cout<<lowerBound<<endl;
    // or we can also print the above as. Since the lowerbound returns the iterator so we can also do this
    //! answer is 5 but we get 6 because iterator is 1 based indexing. so get the ans we subtract 1 from the iterator
    lowerBound=*lower_bound(arr.begin(),arr.end(),6);      //here we dereferenced the iterator
    cout<<lowerBound<<endl;




    
    cout<<"=====================upper bound=========================="<<endl;
    //similary we can also find the upper bound in competitve programming with default c++ method
    //upper_bound=>returns an iterator to the first element greater than a certain value
    int upperBound=upper_bound(arr.begin(),arr.end(),6)-arr.begin(); //! ans is 8
    cout<<upperBound<<endl;
    upperBound=*upper_bound(arr.begin(),arr.end(),6);      //here we dereferenced the iterator
    cout<<upperBound<<endl;





    cout<<"upper and lower bound in range"<<endl;


    //found upper bound and lower bound in range from index 2 to 8
    int lowerBoundIndex=lower_bound(arr.begin()+2,arr.begin()+8,6)-arr.begin(); //! ans is 5
    cout<<lowerBoundIndex<<endl;
    int upperBoundIndex=upper_bound(arr.begin()+2,arr.begin()+8,6)-arr.begin(); //! ans is 8
    cout<<upperBoundIndex<<endl;
}
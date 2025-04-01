#include<bits/stdc++.h>
using namespace std;

// ! finds the maximum sum of k elements that can be picked from either end of the array using a sliding window approach.


//tc is O(2*k) and sc is O(1)
int maxSum(vector<int>&arr,int k){
    int sum=0,maxsum=0;
    for(int i =0;i<k;i++){
        sum+=arr[i];
    }
    maxsum=sum;
    for(int i=0;i<k;i++){
        sum+=arr[arr.size()-1-i]-arr[k-1-i];
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

int main(){
    vector<int> arr={6,2,3,4,7,2,1,7,1};
    int k=4;

    int res=maxSum(arr,k);
    cout<<res<<endl;
}
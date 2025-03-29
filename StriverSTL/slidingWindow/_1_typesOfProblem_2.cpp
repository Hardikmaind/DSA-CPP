#include <bits/stdc++.h>
using namespace std;

// * LONGEST SUBARRAY/SUBSTRING WITH <CONDITION> (VARIABLE WINDOW PATTERN)


//! TC is O(n+n) and SC is O(1)
//! This is a sliding window problem where we need to find the maximum length of subarray with sum less than k.
int maxLengthSubarraySumLessThanK(vector<int>&arr, int k) {
    int l = 0, r = 0, sum = 0, maxLength = 0;
    int n=arr.size();
    while (r < n) {
        sum += arr[r];
        while (sum >= k && l <= r) {
            sum -= arr[l];
            l++;
        }
        maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}


//! here the TC is O(n) and SC is O(1) because we are not using any extra space.
//! This is a sliding window problem where we need to find the maximum length of subarray with sum less than k.
int maxlength(vector<int>&arr,int k){
    int l = 0, r = 0, sum = 0, maxLength = 0;
    int n=arr.size();
    while(r<n){
        sum+=arr[r];
        if(sum>=k && l<=r){         //here why shrink below the maximum length of the subarray which we have already calculated!! For ex if the maxLength we got is 4, then why do furthur more shrinkingbelow the 4 and to satisfy the sum<k. that is what i am doing here. just remove the last element
            sum-=arr[l];
            l++;
        }
        if(sum<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;
    }
    return maxLength;
}

//! TC is O(n^2) and SC is O(1)
int bruteforce(vector<int> &arr,int k){
    int n=arr.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum<k){
                maxLength=max(maxLength,j-i+1);
            }
        }
    }
    return maxLength;
}



int main(){
    vector<int> arr={1,1,1,1,1,2,2,3,4,5,6,7,6,5,6,5,5,4,3,6,2};
   
    int k=8;
    int res=maxLengthSubarraySumLessThanK(arr, k);
    int res2=maxlength(arr,k);
    int res3=bruteforce(arr,k);
    cout<<res<<endl; 
    cout<<res2<<endl;
    cout<<res3<<endl;
    return 0;
}
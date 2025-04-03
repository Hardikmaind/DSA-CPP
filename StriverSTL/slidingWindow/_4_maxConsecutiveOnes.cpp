#include <bits/stdc++.h>
using namespace std;

// ! PROBLEM CAN BE CONVERTED INTO THE FINDING THE LONGEST SUBARRAY WITH MAXZEROS AS K;
int maxConsecutive1s(vector<int>&arr,int k){
    int r=0;
    int l=0;
    int maxlen=0,len=0;
    int n=arr.size();
    int zeroCount=0;
    while (r < n) {
        if (arr[r] == 0) zeroCount++;  // Count zeroes

        while (zeroCount > k) {  // If zero count exceeds k, shrink window
            if (arr[l] == 0) zeroCount--;
            l++;
        }

        maxlen = max(maxlen, r - l + 1);  // Update max length
        r++;  // Expand the window
    }
    return maxlen;
    
}

int maxConsecutive1s2(vector<int>& arr, int k) {
    int l=0,r=0,maxlen=0,zeroc=0;
    while(r<arr.size()){
        if(arr[r]==0) zeroc++;
        if(zeroc>k){                //! here i have used if instead of while because i want to reduce the time complexity
            if(arr[l]==0) {
                zeroc--;
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
    
}
int main(){
    vector<int> arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<maxConsecutive1s(arr,k)<<endl;
    cout<<maxConsecutive1s2(arr,k)<<endl;

}
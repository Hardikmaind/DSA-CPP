#include <bits/stdc++.h>
using namespace std;
// * TYPE WHERE WE HAVE TO FIND THE NUMBER OF subarrays where <CONDITION> 

// ! this works only when all the elements in the array are positive!!

// this kind of problem is solved using using the pattern 2
// Question 1: No of subarrays  with sum =k. 
// here the condition is constant that we want sum =k. and not sum<k. so in this quesiton it is tough to understand whether to expand or shrink the window


// so we break the problem into two parts.
// 1. we will find the number of subarrays with sum <=k.
// 2. we will find the number of subarrays with sum <=k-1.
// 3. we will subtract the two to get the number of subarrays with sum =k.


// Function to count number of subarrays with sum ≤ k
int noOfSubarraysWithSumLessThanOrEqualK(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int l = 0, sum = 0;
    int r=0;

    while (r<n) {
        sum += arr[r];
        
        // Shrink window until sum ≤ k
        while (sum > k && l <= r) {
            sum -= arr[l];
            l++;
        }
        
        // Add all subarrays ending at `r` with sum ≤ k
        count += (r - l + 1);
        r++;
    }
    
    return count;
}

// Function to find number of subarrays with sum exactly equal to k
int noOfSubArrayWithSumK(vector<int>& arr, int k) {
    int lessthank= noOfSubarraysWithSumLessThanOrEqualK(arr, k);
    int lessThanKminus1=noOfSubarraysWithSumLessThanOrEqualK(arr, k - 1);
    cout<<lessthank<<endl;
    cout<<lessThanKminus1<<endl;
    return lessthank - lessThanKminus1;                 ///this works only when all the elements in the array are positive!!
           
}

int main() {
    vector<int> arr = {4, 5, 6, 3, 2, 4, 5, 6, 4, 2, 2, 3, 4, 5, 6, 7, 8, 7, 8, 7, 8, 6, 68, 8, 7};
    int k = 10;
    int res = noOfSubArrayWithSumK(arr, k);
    cout << res << endl;
    return 0;
}